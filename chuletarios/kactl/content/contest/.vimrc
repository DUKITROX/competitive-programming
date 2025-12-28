set relativenumber
set number
set tabstop=4
set shiftwidth=4
set autoindent
set scrolloff=20
syntax on

map FF ggvG"+y
inoremap hj <ESC>
inoremap { {}<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap " ""<left>
inoremap ' ''<left>
inoremap {<CR> {<CR>}<ESC>O

autocmd FileType cpp map <buffer> XX :w<CR>:!g++ -std=gnu++17 -o %< % && ./%<<CR>
autocmd FileType cpp map <buffer> CC :w<CR>:!g++ -std=gnu++17 -o %< % && ./%< < %<.in<CR>
