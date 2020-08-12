#include "head.h"
//按工量打印进度条

int main(int argc,char *argv[])
{
    args_check(argc,3);
    int sfd=socket(AF_INET,SOCK_STREAM,0);
    if(-1==sfd)
    {
        perror("socket");
        return -1;
    }
    printf("sfd=%d\n",sfd);
    struct sockaddr_in ser;
    memset(&ser,0,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(atoi(argv[2]));
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    int ret;
    ret=connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    if(-1==ret)
    {
        perror("connect");
        return -1;
    }
    do{
        ret = signIn(sfd);
    }while(ret != 0);

    while(1)
    {
        ret = tranIns(sfd);
        if(-1 == ret)   break;
    }
    close(sfd);
    return 0;
}


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.003  000.003: --- VIM STARTING ---
000.069  000.066: Allocated generic buffers
000.118  000.049: locale set
000.121  000.003: window checked
000.673  000.552: inits 1
000.694  000.021: parsing arguments
000.694  000.000: expanding arguments
000.708  000.014: shell init
000.854  000.146: Termcap init
000.865  000.011: inits 2
000.962  000.097: init highlight
001.268  000.187  000.187: sourcing /usr/share/vim/vim80/debian.vim
002.012  000.617  000.617: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
002.101  000.750  000.133: sourcing /usr/share/vim/vim80/syntax/synload.vim
011.088  008.952  008.952: sourcing /usr/share/vim/vim80/filetype.vim
011.142  009.833  000.131: sourcing /usr/share/vim/vim80/syntax/syntax.vim
011.166  010.181  000.161: sourcing $VIM/vimrc
011.329  000.011  000.011: sourcing /usr/share/vim/vim80/filetype.vim
011.368  000.007  000.007: sourcing /usr/share/vim/vim80/filetype.vim
011.428  000.031  000.031: sourcing /usr/share/vim/vim80/ftplugin.vim
011.754  000.262  000.262: sourcing /usr/share/vim/vim80/syntax/nosyntax.vim
011.940  000.107  000.107: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
012.015  000.229  000.122: sourcing /usr/share/vim/vim80/syntax/synload.vim
012.036  000.573  000.082: sourcing /usr/share/vim/vim80/syntax/syntax.vim
016.524  004.445  004.445: sourcing /usr/share/vim/vim80/syntax/nosyntax.vim
016.774  000.144  000.144: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
016.855  000.269  000.125: sourcing /usr/share/vim/vim80/syntax/synload.vim
016.877  004.824  000.110: sourcing /usr/share/vim/vim80/syntax/syntax.vim
017.153  000.151  000.151: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
017.243  000.011  000.011: sourcing /usr/share/vim/vim80/filetype.vim
017.304  000.030  000.030: sourcing /usr/share/vim/vim80/indent.vim
018.689  001.277  001.277: sourcing /home/alphabet/.vim/autoload/plug.vim
027.208  000.868  000.868: sourcing /usr/share/vim/vim80/ftoff.vim
042.195  000.018  000.018: sourcing /home/alphabet/.vim/plugged/vim-fugitive/ftdetect/fugitive.vim
042.442  008.957  008.939: sourcing /usr/share/vim/vim80/filetype.vim
042.653  000.011  000.011: sourcing /usr/share/vim/vim80/ftplugin.vim
042.846  000.007  000.007: sourcing /usr/share/vim/vim80/indent.vim
043.816  000.422  000.422: sourcing /usr/share/vim/vim80/pack/dist/opt/matchit/plugin/matchit.vim
043.847  000.753  000.331: sourcing /usr/share/vim/vim80/macros/matchit.vim
048.450  000.165  000.165: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
048.938  000.133  000.133: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
049.426  000.133  000.133: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
049.810  000.128  000.128: sourcing /usr/share/vim/vim80/syntax/syncolor.vim
066.083  017.558  017.164: sourcing /home/alphabet/.vim/colors/onedark.vim
074.422  000.021  000.021: sourcing /home/alphabet/.vimrc.local
074.477  063.283  028.028: sourcing $HOME/.vimrc
074.480  000.054: sourcing vimrc file(s)
074.659  000.055  000.055: sourcing /home/alphabet/.vim/plugged/vim-edit/plugin/vim-edit.vim
074.758  000.045  000.045: sourcing /home/alphabet/.vim/plugged/change-colorscheme/plugin/change-colorscheme.vim
074.831  000.028  000.028: sourcing /home/alphabet/.vim/plugged/prepare-code/plugin/prepare_code.vim
074.970  000.099  000.099: sourcing /home/alphabet/.vim/plugged/vim-buffer/plugin/vim-buffer.vim
075.162  000.122  000.122: sourcing /home/alphabet/.vim/plugged/vimplus-startify/plugin/vimplus-startify.vim
075.518  000.312  000.312: sourcing /home/alphabet/.vim/plugged/tagbar/plugin/tagbar.vim
075.909  000.342  000.342: sourcing /home/alphabet/.vim/plugged/YouCompleteMe/plugin/youcompleteme.vim
081.060  001.020  001.020: sourcing /home/alphabet/.vim/plugged/LeaderF/plugin/leaderf.vim
081.331  000.185  000.185: sourcing /home/alphabet/.vim/plugged/ack.vim/plugin/ack.vim
090.109  008.726  008.726: sourcing /home/alphabet/.vim/plugged/vim-easymotion/plugin/EasyMotion.vim
090.495  000.290  000.290: sourcing /home/alphabet/.vim/plugged/incsearch.vim/plugin/incsearch.vim
090.894  000.090  000.090: sourcing /home/alphabet/.vim/plugged/mathjax-support-for-mkdp/plugin/mathjax.vim
091.474  000.272  000.272: sourcing /home/alphabet/.vim/plugged/markdown-preview.vim/plugin/mkdp.vim
096.181  004.629  004.629: sourcing /home/alphabet/.vim/plugged/auto-pairs/plugin/auto-pairs.vim
096.863  000.155  000.155: sourcing /home/alphabet/.vim/plugged/nerdtree/autoload/nerdtree.vim
097.809  000.379  000.379: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/path.vim
098.055  000.095  000.095: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/menu_controller.vim
098.197  000.054  000.054: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/menu_item.vim
098.357  000.077  000.077: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/key_map.vim
098.595  000.156  000.156: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/bookmark.vim
098.832  000.149  000.149: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/tree_file_node.vim
099.308  000.349  000.349: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/tree_dir_node.vim
099.549  000.151  000.151: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/opener.vim
099.806  000.174  000.174: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/creator.vim
104.026  000.067  000.067: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/flag_set.vim
104.241  000.104  000.104: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/nerdtree.vim
104.548  000.228  000.228: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/ui.vim
104.649  000.017  000.017: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/event.vim
104.760  000.030  000.030: sourcing /home/alphabet/.vim/plugged/nerdtree/lib/nerdtree/notifier.vim
105.206  000.347  000.347: sourcing /home/alphabet/.vim/plugged/nerdtree/autoload/nerdtree/ui_glue.vim
107.146  000.085  000.085: sourcing /home/alphabet/.vim/plugged/nerdtree/nerdtree_plugin/exec_menuitem.vim
107.601  000.441  000.441: sourcing /home/alphabet/.vim/plugged/nerdtree/nerdtree_plugin/fs_menu.vim
107.647  000.032  000.032: sourcing /home/alphabet/.vim/plugged/nerdtree/nerdtree_plugin/vcs.vim
112.268  004.548  004.548: sourcing /home/alphabet/.vim/plugged/nerdtree-git-plugin/nerdtree_plugin/git_status.vim
112.705  000.273  000.273: sourcing /home/alphabet/.vim/plugged/vim-devicons/nerdtree_plugin/webdevicons.vim
112.965  016.694  008.783: sourcing /home/alphabet/.vim/plugged/nerdtree/plugin/NERD_tree.vim
113.259  000.210  000.210: sourcing /home/alphabet/.vim/plugged/tabular/plugin/Tabular.vim
113.715  000.410  000.410: sourcing /home/alphabet/.vim/plugged/vim-fugitive/plugin/fugitive.vim
114.279  000.509  000.509: sourcing /home/alphabet/.vim/plugged/vim-surround/plugin/surround.vim
114.539  000.198  000.198: sourcing /home/alphabet/.vim/plugged/vim-commentary/plugin/commentary.vim
115.067  000.459  000.459: sourcing /home/alphabet/.vim/plugged/vim-endwise/plugin/endwise.vim
115.491  000.085  000.085: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/init.vim
120.002  004.179  004.179: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/parts.vim
121.126  000.107  000.107: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/util.vim
121.153  006.019  001.648: sourcing /home/alphabet/.vim/plugged/vim-airline/plugin/airline.vim
121.239  000.017  000.017: sourcing /home/alphabet/.vim/plugged/vim-airline-themes/plugin/airline-themes.vim
123.321  000.317  000.317: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline.vim
123.417  002.131  001.814: sourcing /home/alphabet/.vim/plugged/vim-devicons/plugin/webdevicons.vim
123.741  000.269  000.269: sourcing /home/alphabet/.vim/plugged/vim-slash/plugin/slash.vim
124.309  000.521  000.521: sourcing /home/alphabet/.vim/plugged/gv.vim/plugin/gv.vim
125.568  001.001  001.001: sourcing /home/alphabet/.vim/plugged/vim-textobj-user/autoload/textobj/user.vim
127.719  003.327  002.326: sourcing /home/alphabet/.vim/plugged/vim-textobj-indent/plugin/textobj/indent.vim
133.350  001.424  001.424: sourcing /home/alphabet/.vim/plugged/vim-textobj-syntax/plugin/textobj/syntax.vim
135.668  002.226  002.226: sourcing /home/alphabet/.vim/plugged/vim-textobj-function/plugin/textobj/function.vim
141.631  005.886  005.886: sourcing /home/alphabet/.vim/plugged/vim-textobj-parameter/plugin/textobj/parameter.vim
141.972  000.258  000.258: sourcing /home/alphabet/.vim/plugged/echodoc.vim/plugin/echodoc.vim
142.226  000.181  000.181: sourcing /home/alphabet/.vim/plugged/clever-f.vim/plugin/clever-f.vim
142.591  000.314  000.314: sourcing /home/alphabet/.vim/plugged/github-complete.vim/plugin/github_complete.vim
142.890  000.064  000.064: sourcing /usr/share/vim/vim80/plugin/getscriptPlugin.vim
143.101  000.194  000.194: sourcing /usr/share/vim/vim80/plugin/gzip.vim
143.476  000.358  000.358: sourcing /usr/share/vim/vim80/plugin/logiPat.vim
143.508  000.012  000.012: sourcing /usr/share/vim/vim80/plugin/manpager.vim
143.706  000.184  000.184: sourcing /usr/share/vim/vim80/plugin/matchparen.vim
148.638  004.915  004.915: sourcing /usr/share/vim/vim80/plugin/netrwPlugin.vim
148.704  000.018  000.018: sourcing /usr/share/vim/vim80/plugin/rrhelper.vim
148.750  000.027  000.027: sourcing /usr/share/vim/vim80/plugin/spellfile.vim
148.987  000.190  000.190: sourcing /usr/share/vim/vim80/plugin/tarPlugin.vim
149.083  000.075  000.075: sourcing /usr/share/vim/vim80/plugin/tohtml.vim
149.283  000.176  000.176: sourcing /usr/share/vim/vim80/plugin/vimballPlugin.vim
149.455  000.149  000.149: sourcing /usr/share/vim/vim80/plugin/zipPlugin.vim
149.565  000.023  000.023: sourcing /usr/share/vim/vim80/pack/dist/opt/matchit/plugin/matchit.vim
149.571  011.438: loading plugins
149.612  000.041: loading packages
150.234  000.286  000.286: sourcing /home/alphabet/.vim/plugged/tabular/autoload/tabular.vim
151.633  001.928  001.642: sourcing /home/alphabet/.vim/plugged/tabular/after/plugin/TabularMaps.vim
151.681  000.141: loading after plugins
151.690  000.009: inits 3
155.941  004.251: reading viminfo
159.798  003.857: setting raw mode
160.018  000.220: start termcap
160.055  000.037: clearing screen
160.945  000.250  000.250: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions.vim
161.193  000.051  000.051: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/quickfix.vim
161.429  000.032  000.032: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/netrw.vim
161.647  000.040  000.040: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/term.vim
161.976  000.059  000.059: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tagbar.vim
162.364  000.170  000.170: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/branch.vim
162.646  000.047  000.047: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/fugitiveline.vim
163.024  000.115  000.115: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/whitespace.vim
163.502  000.056  000.056: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/po.vim
166.908  003.216  003.216: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/wordcount.vim
167.306  000.134  000.134: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tabline.vim
167.560  000.052  000.052: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tabline/autoshow.vim
168.119  000.088  000.088: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tabline/tabs.vim
168.556  000.152  000.152: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tabline/buffers.vim
168.916  000.031  000.031: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/keymap.vim
171.197  000.071  000.071: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/section.vim
171.604  000.182  000.182: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/highlighter.vim
178.789  000.087  000.087: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/themes.vim
179.389  001.114  001.027: sourcing /home/alphabet/.vim/plugged/vim-airline-themes/autoload/airline/themes/onedark.vim
189.125  000.581  000.581: sourcing /home/alphabet/.vim/plugged/vim-airline-themes/autoload/airline/themes/onedark.vim
230.180  000.158  000.158: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/builder.vim
230.787  000.093  000.093: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/default.vim
268.895  102.148: opening buffers
269.098  000.085  000.085: sourcing /home/alphabet/.vim/plugged/LeaderF/autoload/lfMru.vim
270.129  001.149: BufEnter autocommands
270.131  000.002: editing files in windows
272.499  001.280  001.280: sourcing /home/alphabet/.vim/plugged/vimplus-startify/autoload/startify.vim
272.829  000.066  000.066: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tabline/buflist.vim
273.737  000.405  000.405: sourcing /home/alphabet/.vim/plugged/vimplus-startify/autoload/startify/fortune.vim
296.155  004.403  004.403: sourcing /home/alphabet/.vim/plugged/vimplus-startify/syntax/startify.vim
301.026  000.552  000.552: sourcing /home/alphabet/.vim/plugged/YouCompleteMe/autoload/youcompleteme.vim
542.423  265.586: VimEnter autocommands
542.426  000.003: before starting main loop
543.447  000.255  000.255: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tabline/ctrlspace.vim
543.989  000.137  000.137: sourcing /home/alphabet/.vim/plugged/vim-airline/autoload/airline/extensions/tabline/builder.vim
596.932  054.114: first screen update
596.934  000.002: --- VIM STARTED ---
