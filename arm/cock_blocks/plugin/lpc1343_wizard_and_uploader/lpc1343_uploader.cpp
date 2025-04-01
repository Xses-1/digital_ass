#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include <logmanager.h>
#include <projectbuildtarget.h>
#include <projectmanager.h>
#include <cbproject.h>

#include <wx/filefn.h>

#include "lpc1343_uploader.h"

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<lpc1343_uploader> reg(_("lpc1343_uploader"));

    // Menu items
    int idMenuUpload = wxNewId();
}


// events handling
BEGIN_EVENT_TABLE(lpc1343_uploader, cbPlugin)
    EVT_MENU(idMenuUpload, lpc1343_uploader::OnMenuUpload)
END_EVENT_TABLE()

lpc1343_uploader::lpc1343_uploader()
{
    // Load resources
    if(!Manager::LoadResource(_("lpc1343_uploader.zip")))
    {
        NotifyMissingFile(_("lpc1343_uploader.zip"));
    }
}

lpc1343_uploader::~lpc1343_uploader()
{
}

void lpc1343_uploader::OnAttach()
{
}

void lpc1343_uploader::OnRelease(bool appShutDown)
{
}


void lpc1343_uploader::BuildMenu(wxMenuBar* menuBar)
{
    if (!IsAttached())
        return;

    const int pos = menuBar->FindMenu(_T("Project"));

    if (pos != wxNOT_FOUND)
    {
        wxMenu *projectMenu = menuBar->GetMenu(pos);

        projectMenu->AppendSeparator();
        projectMenu->Append (idMenuUpload, _T("Upload to LPC1343"));
    }
    else
    {
        Manager::Get()->GetLogManager()->DebugLog(_T("Could not find Project menu!"));
    }
}

void lpc1343_uploader::OnMenuUpload (wxCommandEvent& event)
{
    // Get filename and project directory
    cbProject *project = Manager::Get()->GetProjectManager()->GetActiveProject();
    wxString buildTarget = project->GetActiveBuildTarget ();
    ProjectBuildTarget *projectBuildTarget = project->GetBuildTarget (buildTarget);

    wxString projectTopDir  = project->GetBasePath();
    wxString outputFilename = projectBuildTarget->GetOutputFilename ();

    // Build command string
#ifdef __LINUX__
    wxString command = _("dd if=") + outputFilename + _(".bin of=/dev/disk/by-id/usb-NXP_LPC134X_IFLASH_ISP000000000-0:0 seek=4");
#endif // __LINUX__

#ifdef __WXOSX__
    wxString command = _("dd if=") + outputFilename + _(".bin of=/dev/disk/by-id/usb-NXP_LPC134X_IFLASH_ISP000000000-0:0 seek=4");
#endif // __WXOSX__	// This is untested and may or may not work! See documentation for more info

#ifdef __WINDOWS__
    wxString command = _("lpc1343_flash ") + outputFilename + _(".bin");
#endif // __WINDOWS__

    wxArrayString stdOut;
    wxArrayString stdErr;

    // Run command
    Manager::Get()->GetLogManager()->Log(command + _("\n"));
    wxSetWorkingDirectory (projectTopDir);
    int result = wxExecute(command.c_str(), stdOut, stdErr);

    // Bring Code::Blocks log to front
    CodeBlocksLogEvent evtSwitch(cbEVT_SWITCH_TO_LOG_WINDOW, LogManager::app_log);
    Manager::Get()->ProcessEvent(evtSwitch);

    // Print stderr and stdout
    for (unsigned int i = 0; i < stdErr.GetCount(); i++)
    {
        Manager::Get()->GetLogManager()->LogError(stdErr[i]);
    }
    for (unsigned int i = 0; i < stdOut.GetCount(); i++)
    {
        Manager::Get()->GetLogManager()->Log(stdOut[i]);
    }

    // Print result
    if (result != 0)
    {
        Manager::Get()->GetLogManager()->LogError(_T("Upload failed!\n"));
    }
    else
    {
        Manager::Get()->GetLogManager()->Log(_T("Upload completed!\n"));
    }
}
