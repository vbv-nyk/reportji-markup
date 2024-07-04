#include "latex.h"

void write_markup_to_file(struct tm *broken_time) {


    mode_t mode = S_IRUSR | S_IWUSR  | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    int fd = open("output.tex", O_RDWR | O_TRUNC | O_CREAT, mode);
dprintf(fd, "\\documentclass[oneside]{book}\n");
dprintf(fd, "\\usepackage[T1]{fontenc}\n");
dprintf(fd, "\\usepackage{graphicx}\n");
dprintf(fd, "\\usepackage{mathptmx}\n");
dprintf(fd, "\\usepackage[a4paper, total={6in, 8in}]{geometry}\n");
dprintf(fd, "\\usepackage{hyperref}\n");
dprintf(fd, "\\usepackage{xcolor}\n");
dprintf(fd, "\\usepackage{color}\n");
dprintf(fd, "\\usepackage{tabularx}\n");

dprintf(fd, "\\definecolor{myorange}{RGB}{255, 165, 0}\n");
// Add the titlesec package and chapter spacing configuration
dprintf(fd, "\\usepackage{titlesec}\n");
dprintf(fd, "\\titleformat{\\chapter}[display]\n");
dprintf(fd, "{\\normalfont\\huge\\bfseries}\n");
dprintf(fd, "{\\chaptername\\ \\thechapter}\n");
dprintf(fd, "{20pt}\n");
dprintf(fd, "{\\Huge}\n");
dprintf(fd, "\\titlespacing*{\\chapter}{0pt}{-20pt}{20pt}\n");
// Custom header and footer for VTU report
dprintf(fd, "\\usepackage{fancyhdr}\n");
dprintf(fd, "\\pagestyle{fancy}\n");
dprintf(fd, "\\fancyhf{}\n");

dprintf(fd, "\\DeclareUnicodeCharacter{2212}{\\ensuremath{-}}");
dprintf(fd, "\\newcommand{\\square}[1]{[ #1 ]}\n");
dprintf(fd, "\\newcommand{\\round}[1]{( #1 )}\n");
dprintf(fd, "\\newcommand{\\curly}[1]{\\{ #1 \\}}\n");
dprintf(fd, "\\newcommand{\\quotes}[1]{\"#1\"}\n");
dprintf(fd, "\\fancyhead[L]{\\color{black}\\textbf{VTU College Report}}\n");
dprintf(fd, "\\fancyhead[R]{\\color{black}\\textbf{\\leftmark}}\n");
dprintf(fd, "\\fancyfoot[L]{\\color{black}\\textbf{Department of XYZ}}\n");
dprintf(fd, "\\fancyfoot[C]{\\color{black}\\thepage}\n");
dprintf(fd, "\\fancyfoot[R]{\\color{black}\\textbf{%d %d %d %d %d}}\n", broken_time->tm_mon, broken_time->tm_hour, broken_time->tm_hour);

dprintf(fd, "\\renewcommand{\\headrule}{\\color{myorange}\\hrule height 0.4pt}\n");
dprintf(fd, "\\renewcommand{\\footrule}{\\color{myorange}\\hrule height 0.4pt}\n");

dprintf(fd, "\\fancypagestyle{plain}{\n");
dprintf(fd, "  \\fancyhf{}\n");
dprintf(fd, "  \\fancyhead[L]{\\color{black}\\textbf{VTU College Report}}\n");
dprintf(fd, "  \\fancyhead[R]{\\color{black}\\textbf{\\leftmark}}\n");
dprintf(fd, "  \\fancyfoot[L]{\\color{black}\\textbf{Department of XYZ}}\n");
dprintf(fd, "  \\fancyfoot[C]{\\color{black}\\thepage}\n");
dprintf(fd, "  \\fancyfoot[R]{\\color{black}\\textbf{15 June 2024}}\n");
dprintf(fd, "  \\renewcommand{\\headrule}{\\color{myorange}\\hrule height 0.4pt}\n");
dprintf(fd, "  \\renewcommand{\\footrule}{\\color{myorange}\\hrule height 0.4pt}\n");
dprintf(fd, "}\n");
dprintf(fd, "\\linespread{1.5}\n");
dprintf(fd,"\\usepackage{float}\n");
dprintf(fd,"\\restylefloat{figure}\n");

dprintf(fd, "\\begin{document}\n");


dprintf(fd, "\\setcounter{page}{0}\n");  // Reset page counter to 1
dprintf(fd, "\\tableofcontents\n");
dprintf(fd, "\\newpage");
dprintf(fd, "\\listoffigures\n");
dprintf(fd, "\\clearpage\n"); // Start new page after TOC

dprintf(fd, "\\pagenumbering{arabic}\n"); // Start Arabic page numbering
dprintf(fd, "\\setcounter{page}{1}\n");  // Reset page counter to 1


   for(int i=0; i<total_pages; i++) {
       dprintf(fd,"\\newpage\n");
       for(int j=0; j<pages[i]->num_elements; j++)
            dprintf(fd, "%s", output[i].outputPages->markup[j]);
       dprintf(fd,"\n");
   }
   dprintf(fd,"\\end{document}");

}