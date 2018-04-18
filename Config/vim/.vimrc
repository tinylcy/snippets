" 定义快捷键的前缀，即<Leader>
let mapleader=";"

" 开启文件类型侦测
filetype on
" 根据不同的类型加载对应的插件
filetype plugin on

" 定义快捷键到行尾和行首
nmap LB 0
nmap LE $

" 设置快捷键将选中的文本复制至系统剪贴板
vnoremap <Leader>y "+y

" 定义快捷键关闭当前分割窗口
nmap <Leader>q :q<CR>

" 定义快捷键保存当前窗口内容
nmap <Leader> WQ :w<CR>

" 定义快捷键保存所有窗口内容并退出
nmap <Leader> WQ :wa<CR>:q<CR>

" *.cpp 和 *.h 间切换
nmap <silent> <Leader>sw :FSHere<cr>

" 开启实时搜索功能
set incsearch

" 搜索时大小写不敏感
set ignorecase

" 关闭兼容模式
set nocompatible

" vim 自身命令行模式智能补全
set wildmenu 

" 开启语法高亮功能
syntax enable
" 允许用指定语法高亮配色方案替换默认方案
syntax on

" 总是显示状态栏
set laststatus=2
" 显示光标当前位置
set ruler
" 开启行号显示
set number
" 高亮显示当前行/列
set cursorline
set cursorcolumn
" 高亮显示搜索结果
set hlsearch

" 进制折行
set nowrap

" vundle 环境设置
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
" vundle 管理的插件列表必须位于 vundle#begin() 和 vundle#end() 之间
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'altercation/vim-colors-solarized'
Plugin 'Lokaltog/vim-powerline'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'tomasr/molokai'
Plugin 'dracula/vim'
Plugin 'derekwyatt/vim-fswitch'
Plugin 'majutsushi/tagbar'
" 插件列表结束
call vundle#end()
filetype plugin indent on

" 配色方案
set background=dark
colorscheme dracula

" 进制光标闪烁
set gcr=a:block-blinkon0
" 禁止显示滚动条
set guioptions-=l
set guioptions-=L
set guioptions-=r
set guioptions-=R
" 禁止显示菜单和工具条
set guioptions-=m
set guioptions-=T

" 设置状态栏主题风格
let g:Powerline_colorscheme='solarized256'

" 自适应不同语言的智能缩进
filetype indent on
" 将制表符扩展为空格
set expandtab
" 设置编辑时制表符占用空格数
set tabstop=4
" 设置格式化时制表符占用空格数
set shiftwidth=4
" 让 vim 把连续数量的空格视为一个制表符
set softtabstop=4

