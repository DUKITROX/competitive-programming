set relativenumber
set number
set tabstop=4
set shiftwidth=4
set autoindent
set scrolloff=20
set ru
syntax on
"set cursorline

nnoremap FF gg"+yG
inoremap hj <ESC>
inoremap { {}<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap " ""<left>
inoremap ' ''<left>
inoremap {<CR> {<CR>}<ESC>O

""ca Hash w !tr -d '[:space:]' \| md5sum \| cut -c-6
command! -range=% Hash <line1>,<line2>w !./hash.sh