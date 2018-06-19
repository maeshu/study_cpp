#include <iostream>


int flag = 0;

struct string_data
{
	char* buffer;
	int length;
};

struct string_data input(struct string_data *data);
void output(struct string_data *data);
void free_buffer(struct string_data *data);

int main()
{
	struct string_data moji;
	buffer = dynamic_cast<char*>(malloc(sizeof(char)));
	if (moji.buffer == nullptr)
	{
		return -1;
	}
		while (flag != 1)
		{
			output(moji.buffer, input());
		}
	free_buffer(moji.buffer);
}


struct string_data input(struct string_data *data)
{
	do
	{
		data->buffer[data->length] = std::getchar();
		if (data->buffer[data->length] == 27)
		{
			flag = 1;
			break;
		}
		data->buffer = (char*)realloc(data->buffer, sizeof(char) * (++data->length + 2));
	} while (data->buffer[data->length] != '\0');
	data->buffer[data->length] = '\0';
	return data->length;
}

void output(struct string_data *data)
{
	for (int i = 0; i < data->length; i++)
	{
		std::putchar(data->buffer[i]);
	}
}

void free_buffer(struct string_data *data)
{
	if (data->buffer)
	{
	free(data->buffer);
	}
	data-buffer = nullptr;
}
