" UI
	if has('syntax')
		filetype off
		syntax off
	endif

	set nocp enc=utf-8 shm+=aWIF notgc bg=light ls=2 stl+=%F nosmd cc=80

" Colorscheme
	hi! Normal      ctermbg=white     ctermfg=black
	hi! link        VertSplit         Normal
	hi! link        CursorLine        Normal
	hi! link        LineNr            Normal
	hi! link        Wildmenu          Normal
	hi! link        EndOfBuffer       Normal
	hi! Visual      ctermbg=lightgray ctermfg=black
	hi! link        Search            Visual 
	hi! link        MatchParen        Visual 
	hi! ColorColumn ctermbg=black     ctermfg=white
	hi! link        StatusLine        ColorColumn 

" UX
	set ut=300 mouse= hid nobk noswf nu rnu ic scs hls sb spr  

	if has('clipboard')
		set clipboard+=unnamedplus
	endif

" Indentation
	set ts=2 sts=0 sw=2 si ci 

" VC
	if has('persistent_undo')
		let s:udir = expand('~/.vim/undo') 
		if !isdirectory(s:udir)
			call mkdir(s:udir, "p")
		endif
		let &udir = s:udir
		set udf 
	endif

" Bindings
	let mapleader=' '

	nnoremap k  kzz
	nnoremap j  jzz

	nnoremap <leader>v :vsplit %<CR>
	nnoremap <C-h>     :vertical resize -10<CR>
	nnoremap <C-j>     :horizontal resize +10<CR>
	nnoremap <C-k>     :horizontal resize -10<CR>
	nnoremap <C-l>     :vertical resize +10<CR>

	nnoremap <leader>n :nohlsearch<CR>
	nnoremap <leader>m :make<CR>
	nnoremap <leader>e :Lexplore<CR>

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

	nnoremap <silent>  <leader>c :call ToggleQuickfix()<CR>

	cabbrev w!! exe 'sil! write !sudo tee % >/dev/null' <bar> edit!
	cabbrev f find

" Autocmds
	autocmd FileType *     setlocal formatoptions-=cro
	autocmd FileType netrw setlocal bufhidden=wipe
