#include "latex.h"

void write_markup_to_file() {
    mode_t mode = S_IRUSR | S_IWUSR  | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    int fd = open("output.tex", O_RDWR | O_TRUNC | O_CREAT, mode);
    dprintf(fd,"\\documentclass{article}\n");
    dprintf(fd,"\\usepackage{graphicx}\n");
    dprintf(fd,"\\begin{document}\n\n");

   for(int i=0; i<total_pages; i++) {
       dprintf(fd,"\\newpage\n");
       for(int j=0; j<pages[i]->num_elements; j++)
            dprintf(fd, "%s", output[i].outputPages->markup[j]);
       dprintf(fd,"\n");
   }
   dprintf(fd,"\\end{document}");

}