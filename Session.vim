let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/rsyncdata/data/proj/etec/EE3/D11/lab/digital_ass
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 ass1/computer.hpp
badd +44 ass1/program.cpp
badd +0 term://~/rsyncdata/data/proj/etec/EE3/D11/lab/digital_ass//7766:bash
badd +11 ass1/Makefile
badd +42 ass1/computer.cpp
badd +23 ass1/program.hpp
argglobal
%argdel
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit ass1/computer.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 22 + 24) / 48)
exe 'vert 1resize ' . ((&columns * 79 + 80) / 160)
exe '2resize ' . ((&lines * 23 + 24) / 48)
exe 'vert 2resize ' . ((&columns * 79 + 80) / 160)
exe 'vert 3resize ' . ((&columns * 80 + 80) / 160)
argglobal
balt ass1/computer.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 13 - ((12 * winheight(0) + 11) / 22)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 13
normal! 022|
wincmd w
argglobal
if bufexists(fnamemodify("ass1/computer.cpp", ":p")) | buffer ass1/computer.cpp | else | edit ass1/computer.cpp | endif
if &buftype ==# 'terminal'
  silent file ass1/computer.cpp
endif
balt ass1/program.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 22 - ((11 * winheight(0) + 11) / 23)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 22
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("term://~/rsyncdata/data/proj/etec/EE3/D11/lab/digital_ass//7766:bash", ":p")) | buffer term://~/rsyncdata/data/proj/etec/EE3/D11/lab/digital_ass//7766:bash | else | edit term://~/rsyncdata/data/proj/etec/EE3/D11/lab/digital_ass//7766:bash | endif
if &buftype ==# 'terminal'
  silent file term://~/rsyncdata/data/proj/etec/EE3/D11/lab/digital_ass//7766:bash
endif
balt ass1/program.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 31 - ((25 * winheight(0) + 23) / 46)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 31
normal! 04|
wincmd w
exe '1resize ' . ((&lines * 22 + 24) / 48)
exe 'vert 1resize ' . ((&columns * 79 + 80) / 160)
exe '2resize ' . ((&lines * 23 + 24) / 48)
exe 'vert 2resize ' . ((&columns * 79 + 80) / 160)
exe 'vert 3resize ' . ((&columns * 80 + 80) / 160)
tabnext
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
tabnext 2
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
