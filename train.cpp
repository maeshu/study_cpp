#include <iostream>
#define MAX_S 256

int input(int[], int);
void free_buffer(void);
void output(int[], int);
void re_allocate(int);
int (*buf)[MAX_S];
int line_cnt = 1;

int main()
{
        buf = (int(*)[MAX_S])malloc(sizeof(int) * MAX_S);
        if (buf == NULL)
        {
                return -1;
        }
        do
        {
                re_allocate(line_cnt++);
                output(*buf, input(*buf, MAX_S));
        } while(std::getchar() != 27);

}


int input(int s[], int lim)
{
        int c, i;
        for (i = 0; i < lim - 1 && (c = std::getchar()) != '\n'; i++)
        {
                s[i] = c;
        }
        s[i] = '\0';
        return i;
}

void output(int s[], int num)
{
        for (int i = 0; i < num; i++)
        {
                std::putchar(s[i]);
        }
}

void re_allocate(int i){
        int (*tmp)[MAX_S] = NULL;
        tmp = (int(*)[MAX_S])realloc(buf, i * sizeof(int) * MAX_S);
        if (!tmp) {
                free_buffer();
        }
        buf = tmp;
}


void free_buffer()
{
        if (buf)
                free(buf);
        buf = NULL;
}
