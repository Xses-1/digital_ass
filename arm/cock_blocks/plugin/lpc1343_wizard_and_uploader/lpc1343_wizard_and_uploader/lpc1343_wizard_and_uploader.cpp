#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "lpc1343_wizard_and_uploader.h"

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<lpc1343_wizard_and_uploader> reg(_T("lpc1343_wizard_and_uploader"));
}

// constructor
lpc1343_wizard_and_uploader::lpc1343_wizard_and_uploader()
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("lpc1343_wizard_and_uploader.zip")))
    {
        NotifyMissingFile(_T("lpc1343_wizard_and_uploader.zip"));
    }
}

// destructor
lpc1343_wizard_and_uploader::~lpc1343_wizard_and_uploader()
{
}

void lpc1343_wizard_and_uploader::OnAttach()
{
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void lpc1343_wizard_and_uploader::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}

int lpc1343_wizard_and_uploader::GetCount() const
{
    return 0;
}

TemplateOutputType lpc1343_wizard_and_uploader::GetOutputType(int index) const
{
    return totProject;
}

wxString lpc1343_wizard_and_uploader::GetTitle(int index) const
{
    return _T("My wizard");
}

wxString lpc1343_wizard_and_uploader::GetDescription(int index) const
{
    return _T("My wizard's description");
}

wxString lpc1343_wizard_and_uploader::GetCategory(int index) const
{
    return _T("My wizard's category");
}

const wxBitmap& lpc1343_wizard_and_uploader::GetBitmap(int index) const
{
    return m_Bitmap;
}

wxString lpc1343_wizard_and_uploader::GetScriptFilename(int index) const
{
    return wxEmptyString;
}

CompileTargetBase* lpc1343_wizard_and_uploader::Launch(int index, wxString* createdFilename)
{
    NotImplemented(_T("lpc1343_wizard_and_uploader::Launch()"));
    if (createdFilename)
        *createdFilename = wxEmptyString;
    return 0;
}
