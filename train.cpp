#include <iostream>
int input();
void free_buffer(int*);
void output(int*, int);
int* buf;
int flag = 0;
//int buf_counter = 0;
int main()
{
	buf = (int*)realloc(nullptr, sizeof(int));
        if (buf == nullptr)
        {
                return -1;
        }

	while(flag != 1)
	{
        output(buf, input());
	}
	free_buffer(buf);
}
int input()
{
	/*
        buf = (int*)realloc(nullptr, sizeof(int));
        if (buf == nullptr)
        {
                return -1;
        }
	*/
	int buf_counter = 0;
	do
	{
		*(buf+buf_counter) = std::getchar();
		if(*(buf+buf_counter) == 27)
		{
		flag = 1;
		break;
		}	
		buf = (int*)realloc(buf, sizeof(int)*(++buf_counter + 2));
	}while(*(buf+buf_counter) != '\0');
	*(buf+buf_counter) = '\0';
	return buf_counter;
}

void output(int s[], int num)
{
        for (int i = 0; i < num; i++)
        {
                std::putchar(s[i]);
        }
}
/*
void re_allocate(int i){
        int (*tmp)[MAX_S] = NULL;
        tmp = (int(*)[MAX_S])realloc(buf, i * sizeof(int) * MAX_S);
        if (!tmp) {
                free_buffer();
        }
        buf = tmp;
}

*/
void free_buffer(int* s)
{
        if (s)
        {
	free(s);
        }
        s = nullptr;
}
