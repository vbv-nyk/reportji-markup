#include "output.h"

Output* output;

char* parse_title(ElementDefinition title) {
   char* markup = (char*) malloc(1000);
   sprintf(markup, "\\section{%s}\n", title.title->text);
   return markup;
}
char* parse_subtitle(ElementDefinition subtitle) {
   char* markup = (char*) malloc(1000);
   sprintf(markup, "\\title{%s}\n", subtitle.subtitle->text);
   return markup;
}
char* parse_heading(ElementDefinition heading) {
   char* markup = (char*) malloc(1000);
   sprintf(markup, "\\chapter{%s}\n", heading.heading->text);
   return markup;
}
char* parse_author(ElementDefinition author) {
   char* markup = (char*) malloc(1000);
   sprintf(markup, "\\hfill \\textbf{%s}\\par\n", author.author->text);
   return markup;
}
char* parse_date(ElementDefinition date) {
   char* markup = (char*) malloc(1000);
   sprintf(markup, "\\hfill \\textbf{%s}\\par\n", date.date->text);
   return markup;
}
char* parse_paragraphs(ElementDefinition paragraphs) {
   char* markup = (char*) malloc(10000);
   sprintf(markup, "%s\\par\n", paragraphs.paragraphs->text[0]);

   for(int i=1; i<paragraphs.paragraphs->count; i++)  {
       sprintf(markup + strlen(markup), "%s\\par\n",paragraphs.paragraphs->text[i]);
   }
   return markup;
}

char* parse_items(ElementDefinition items) {
   char* markup = (char*) malloc(10000);
   markup[0] = '\0';
   strcat(markup, "\\begin{itemize}\n");
   for(int i=0; i<items.items->count; i++)  {
       sprintf(markup + strlen(markup), "\\item %s\n",items.items->text[i]);
   }
   strcat(markup, "\\end{itemize}\n");
   return markup;
}
char* parse_figures(ElementDefinition figures) {
   char* markup = (char*) malloc(1000);
   markup[0] = '\0';
   strcat(markup, "\\begin{figure}[h]\n\\centering\n");
   for(int i=0; i<figures.figures->count; i++) {
       sprintf(markup + strlen(markup), "\\includegraphics{sample.png}\n\\caption{%s}\n", figures.figures->figureContent[i]->caption);
   }
   strcat(markup, "\\end{figure}\n");
   return markup;
}

char* parse_citations(ElementDefinition citations) {
   char* markup = (char*) malloc(1000);
   markup[0] = '\0';
   strcat(markup, "\\begin{thebibliography}{100}\n");

   for(int i=0; i < citations.citations->count; i++) {
       sprintf(markup + strlen(markup), "\\bibitem{%d}\n%s\n", i, citations.citations->text[i]);
   }
   
   strcat(markup, "\\end{thebibliography}\n");

   return markup;
}

char* parse_differences(ElementDefinition differences) {
    char* markup = (char*) malloc(10000);
    markup[0] = '\0';
    strcat(markup, "\\begin{table}[h!]\n");
    strcat(markup, "\\centering\n");
    strcat(markup, "\\begin{tabular}{|");
    for(int i=0; i<differences.differences->count; i++){
        //printf("%d", differences.differences->count);
        strcat(markup," c |");
    }
    strcat(markup, "}\n");
    strcat(markup, "\\hline\n");
    for(int j=0; j<differences.differences->differenceColumns[0]->rows_count; j++) {
        for(int i=0; i<differences.differences->count; i++) {
            if(i == differences.differences->count - 1) {
                sprintf(markup + strlen(markup), "\\textbf{%s} \\\\ \\hline\n", differences.differences->differenceColumns[i]->content[j]);
            } else {
                sprintf(markup + strlen(markup), "\\textbf{%s} & ", differences.differences->differenceColumns[i]->content[j]);                
            }
        }
    }
    strcat(markup, "\\end{tabular}\n");
    strcat(markup, "\\label{table:1}\n");
    strcat(markup, "\\end{table}\n");
   return markup;
}


char* element_to_latex(Element* element) {
    switch(*element->type) {
        case TITLE:
            return parse_title(*element->content);
        case SUBTITLE:
            return parse_subtitle(*element->content);
        case HEADING:
            return parse_heading(*element->content);
        case AUTHOR:
            return parse_author(*element->content);
        case DATE:
            return parse_date(*element->content);
        case PARAGRAPHS:
            return parse_paragraphs(*element->content);
        case ITEMS:
            return parse_items(*element->content);
        case FIGURES:
            return parse_figures(*element->content);
        case CITATIONS:
            return parse_citations(*element->content);
        case DIFFERENCES:
            return parse_differences(*element->content);
    }
}


void init_output() {
    output = (Output*)malloc(sizeof(Output) * total_pages);
    for(int i=0; i < total_pages; i++) {
        OutputPage* outputPages = (OutputPage*)malloc(sizeof(OutputPage));
        char** markup = (char**)malloc(pages[i]->num_elements*(sizeof(char*)));
        //printf("Page: %s\n", pages[i]->name );
        for(int j=0; j < pages[i]->num_elements; j++) {
            char* output_markup = element_to_latex(pages[i]->elements[j]);
            markup[j] = output_markup;
            //printf("%s", markup[j]);
        }
        outputPages->markup = markup;
        outputPages->name = strdup(pages[i]->name);
        output[i].outputPages =  outputPages;
        //free(pages[i]->name);
        //free(pages[i]->content);
        //free(pages[i]->elements);
    }
}