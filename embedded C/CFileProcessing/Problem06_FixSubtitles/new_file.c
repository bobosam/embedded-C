0 #include <stdio.h>
1 #include <stdlib.h>
2 
3 int main(int argc, char** argv) {
4     int ch, count = 0;
5 
6     FILE *file = fopen("main.c", "r");
7     FILE *new_file = fopen("new_file.c", "w");
8     
9     if (file && new_file)
10     {
11         fprintf(new_file, "%d ", count);
12         
13         while ((ch = fgetc(file)) != EOF)
14         {
15             fprintf(new_file, "%c", ch);
16             if (ch == '\n')
17             {
18                 count++;
19                 fprintf(new_file, "%d ", count);
20             }
21         }
22 
23         fclose(file);
24         fclose(new_file);
25     }
26     else
27     {
28         printf("no such file.");
29     }
30     return (EXIT_SUCCESS);
31 }