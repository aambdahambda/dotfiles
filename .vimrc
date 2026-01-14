filetype off 
syntax off

set enc=utf-8 shm+=asWIF tgc bg=light ls=2 stl=%F noru nosmd nosc 

hi! Normal      guibg=#ffffea   guifg=#333333 ctermbg=white     ctermfg=black
hi! link        VertSplit       Normal
hi! link        CursorLine      Normal
hi! link        LineNr          Normal
hi! link        Wildmenu        Normal
hi! link        EndOfBuffer     Normal
hi! Visual      guibg=lightgray guifg=#333333 ctermbg=lightgray ctermfg=black
hi! link        Search          Visual 
hi! link        MatchParen      Visual 
hi! link        StatusLineNC    Visual	
hi! ColorColumn guibg=#333333   guifg=#ffffea ctermbg=black     ctermfg=white cterm=none
hi! link        StatusLine      ColorColumn	

set ut=300 clipboard=unnamedplus mouse= hid nu rnu nobk noswf  
set ic scs hls sb spr ts=2 sts=0 sw=2 et ai si ci 

if has('persistent_undo')
	let s:udir = expand('~/.vim/undo') 
	if !isdirectory(s:udir)
		call mkdir(s:udir, "p")
	endif
	let &udir = s:udir
	set udf 
endif

function! ToggleQuickfix()
	if exists('*getwininfo')
		let l:quickfix_wins = filter(getwininfo(), 'v:val.quickfix')
		if !empty(l:quickfix_wins)
			cclose
			return
		endif
	endif
	if len(getqflist()) > 0
		copen 15
	else
		echom "Quickfix list is empty: can't open."
	endif
endfunction

let mapleader=' '
nnoremap k         kzz
nnoremap j         jzz
nnoremap <leader>v :vsplit %<CR>
nnoremap <C-h>     :vertical resize -10<CR>
nnoremap <C-j>     :horizontal resize +10<CR>
nnoremap <C-k>     :horizontal resize -10<CR>
nnoremap <C-l>     :vertical resize +10<CR>
nnoremap <leader>n :nohlsearch<CR>
nnoremap <leader>m :make<CR>
nnoremap <leader>e :Lexplore<CR>
nnoremap <silent>  <leader>c :call ToggleQuickfix()<CR>

cabbrev w!! exe 'sil! write !sudo tee % >/dev/null' <bar> edit!
cabbrev f find

au FileType *     setlocal formatoptions-=cro
au FileType netrw setlocal bufhidden=wipe
au BufEnter *     sil!     lcd %:p:h
