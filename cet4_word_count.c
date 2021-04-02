// cet4_word_count.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct list
{
	char word[25];
	char count;
}list1;
struct list X[3000];

int main()
{
	void quicksort(list1 arr[],int low,int high);
	//*****************************
	//variuable define
	char test[3000] = { ' ' }, temp[25] = { ' ' };
	int i = 0, j = 0, k = 0, n = 0;
	FILE* out;
	FILE* in;
	//***********************	variuable define end

	//*******************************
	//		put data for outfile.dat
	out = fopen("C:\\Users\\1952593542\\Desktop\\c program\\vs2019_project\\cet4_word_count\\cet4_word_count\\outfile.dat", "r+");
	if (out == NULL)
	{
		puts("out flie error.");
		return -1;
	}
	fgets(test, 3000, out);
	for (int a = 0; a < 300; a++)
	{
		printf("%c", test[a]);
	}
	puts(" ");
puts("print end.");
//***************1l*8		put data for outfile.dat end

//**********************************
//		kiner program
for (i = 0; i < sizeof(test); i++)
{
	if (test[i] == '\0')	break;	//字符结束标记
	/*if (test[i] == ' '||(!((test[0]>='a' && test[0] <= 'z') || (test[0]>='A' && test[0] <= 'Z'))))	*/
	if (!((test[0] >= 'a' && test[0] <= 'z') || (test[0] >= 'A' && test[0] <= 'Z')))
		continue;				//跳过空格和非英文字符
	k = 0;						//k设置为字符串赋值的索引
	for (j = 0; j < 24; j++)	//copy test to temp
	{
		if ((test[i] != ' ' && test[i] != '\0') && ((test[i] >= 'a' && test[i] <= 'z') || (test[i] >= 'A' && test[i] <= 'Z')))
		{
			temp[k] = test[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = '\0';
			//i++;				error
			break;
		}
	}//string temp copy end;

	puts(temp);
	if ((temp[0] <= 'z' && temp[0] >= 'a') || (temp[0] <= 'Z' && temp[0] >= 'A'))//确保不是“\0”、空格
	{
		for (int m = 0; m < sizeof(X); m++)
		{
			if (strcmp(strlwr(temp), strlwr(X[m].word)) != 0 && X[m].word[0] == '\0')//temp!=word and word[0] is null
			{
				strcpy(X[m].word, temp);//word 可能不够大
				X[m].count = 1;
				break;
			}
			if (strcmp(strlwr(temp), strlwr(X[m].word)) == 0 && X[m].word[0] != '\0')
			{
				X[m].count++;
				break;
			}
		}
	}

	strcpy(temp, "                        ");//初始化temp
}
//*******************88888		end  kinoer
quicksort(X, 0, 2999);

//&******************************************************
//test 
puts("testing test[i]!=NULL:");
for (int a = 0; a < 360; a++)
{
	printf("%s ", X[a].word);
}
puts(" ");
puts("test print end.");
//		test end
//**********************************************************

//*********************************************
//		out file to result.dat 
in = fopen("result.txt", "w+");
if ((in == NULL))
{
	puts("in  flie error.");
	return -2;
}
for (int cnt = 0; cnt < 3000; cnt++)
{
	fprintf(in, "%-25s\t\t%d\n", X[cnt].word, X[cnt].count);
}
//fwrite(&X[0], sizeof(X[0]), 3000, in);
//		end out file result.dat
//************************************
printf("\t%d\n", &X[0].word == &X[1].word);//word 比较错误。可能是在装入时比较失误
printf("*%s*\t", X[0].word);
printf("*%s*\n", X[1].word);
fclose(out);
fclose(in);
puts("ok");
return 0;
}

//快速排序
void quicksort(list1 arr[], int low, int high)
{
	int left = low, right = high;
	int temp = arr[low].count;
	while (low < high)
	{
		while ((arr[low].count >= arr[high].count) && (low < high))
			high--;
		if (low < high)
			arr[low++].count = arr[high].count;
		while ((arr[low].count <= arr[high].count) && (low < high))
			low++;
		if (low < high)
			arr[high--].count = arr[low].count;
	}
	arr[low].count = temp;
	if (left < low - 1)
	{
		quicksort(arr, left, low - 1);
	}
	if (low + 1 < right)
		quicksort(arr, low + 1, right);
}