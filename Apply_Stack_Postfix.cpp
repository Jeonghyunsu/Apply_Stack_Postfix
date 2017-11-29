/*
*	Linux 환경에서 실행
*/

#include <cstdlib>
#include <iostream>
#include <stack>
#include <cstring>
#include <stdio.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define STRING_SIZE 512

using namespace std;

bool Balanced_Ps(char *str);//완전한 괄호치기 여부('(')
bool Balanced_Pm(char *str);//완전한 괄호치기 여부('[')
bool Balanced_Pl(char *str);//완전한 괄호치기 여부('{')
char* Postfix(char *str);//인픽스를 포스트픽스로 바꾸기
double Priority(char str1);//연산자와 괄호의 우선순위
void Calc(char *postresult);//포스트픽스 계산
char Result(char A, char OP, char B);//파일을 열어 연산의 조건 리턴

int main()
{
	char str[STRING_SIZE];
	char *postResult;

	cout << "원하는 수식을 입력해주세요!" << endl;
	cin >> str;

	if (Balanced_Ps(str) && Balanced_Pm(str) && Balanced_Pl(str))
	{
		postresult = Postfix(str);
		Calc(postResult);
	}
	else
	{
		cout << "Not Balanced parenthesis" << endl;
	}
	return 0;
}

char Result(char A, char OP, char B)
{
	char eval[STRING_SIZE];//연산자의 조건을 담는 배열
	int fd;
	size_t nread;

	fd = open("operations.txt", O_RDONLY);
	nread = read(fd, eval, 512);
	close(fd);

	if (OP == eval[0])
	{
		if (A == 'a' && B == 'a')
			return eval[2];
		else if (A == 'a' && B == 'b')
			return eval[4];
		else if (A == 'a' && B == 'c')
			return eval[6];
		else if (A == 'b' && B == 'a')
			return eval[8];
		else if (A == 'b' && B == 'b')
			return eval[10];
		else if (A == 'b' && B == 'c')
			return eval[12];
		else if (A == 'c' && B == 'a')
			return eval[14];
		else if (A == 'c' && B == 'b')
			return eval[16];
		else if (A == 'c' && B == 'c')
			return eval[18];
	}
	else if (OP == eval[20])
	{
		if (A == 'a' && B == 'a')
			return eval[22];
		else if (A == 'a' && B == 'b')
			return eval[24];
		else if (A == 'a' && B == 'c')
			return eval[26];
		else if (A == 'b' && B == 'a')
			return eval[28];
		else if (A == 'b' && B == 'b')
			return eval[30];
		else if (A == 'b' && B == 'c')
			return eval[32];
		else if (A == 'c' && B == 'a')
			return eval[34];
		else if (A == 'c' && B == 'b')
			return eval[36];
		else if (A == 'c' && B == 'c')
			return eval[38];
	}
	else if (OP == eval[40])
	{
		if (A == 'a' && B == 'a')
			return eval[42];
		else if (A == 'a' && B == 'b')
			return eval[44];
		else if (A == 'a' && B == 'c')
			return eval[46];
		else if (A == 'b' && B == 'a')
			return eval[48];
		else if (A == 'b' && B == 'b')
			return eval[50];
		else if (A == 'b' && B == 'c')
			return eval[52];
		else if (A == 'c' && B == 'a')
			return eval[54];
		else if (A == 'c' && B == 'b')
			return eval[56];
		else if (A == 'c' && B == 'c')
			return eval[58];
	}
	else
		return 0;
}

void Calc(char *postresult)
{
	stack<char>operands;//포스트픽스를 연산하기 위한 스텍

	char calcA;
	char calcB;
	char finally;

	int i = 0;
	while (postresult[i] != '\0')
	{
		if (postresult[i] == 'a' || postresult[i] == 'b' || postresult[i] == 'c')//operand인 경우
			operands.push(postresult[i]);
		else if (postresult[i] == '@' || postresult[i] == '#' || postresult[i] == '&')//operator인 경우
		{
			calcB = operands.top();
			operands.pop();
			calcA = operands.top();
			operands.pop();

			operands.push(Result(calcA, postresult[i], calcB));	//인자를 이용하여 연산 (operandA operator operandB)
		}
		i++;
	}
	finally = operands.top();//최종 연산된 값
	operands.pop();
	if (!operands.empty())
	{
		cout << "error!!" << endl;
		exit(0);
	}
	cout << "최종 결과는 : " << finally << endl;
}
bool Balanced_Ps(char *str)
{
	stack<char>balance;//완전한 괄호치기 평가('('를 넣고 뺌)
	stack<char>balanceR;//')'를 넣고 뺌
	int i = 0;
	int evalL = 0;//'('넣었던 수
	int evalR = 0;//')'넣었던 수
	int real = 0;

	while (str[i] != '\0')
	{

		if (str[0] == 'E' && str[1] == 'O' && str[2] == 'I')
		{
			cout << "EXIT!!" << endl;
			exit(-1);
		}
		if (str[0] == 'e' && str[1] == 'o' && str[2] == 'i')
		{
			cout << "EXIT!!" << endl;
			exit(-1);
		}

		if (str[i] == '(')
		{
			balance.push('(');
			evalL++;
		}
		else if (str[i] == ')' && evalL>evalR)//'('가 ')'보다 많아야 연산이 가능
		{
			balance.pop();
			evalR++;
		}
		else if (str[i] == ')')//')'가 더 많은 경우
		{
			balanceR.push(')');
			evalR++;
		}
		i++;
	}
	if (evalL == evalR)//완전 괄호치기가 된 경우
	{
		for (; !balanceR.empty();)
		{
			balanceR.pop();
		}
	}
	if (!balanceR.empty())//')'가 더 많은 경우 
		return false;

	if (!balance.empty())//'('가 남아있는 경우
		return false;

	else
		return true;


}
bool Balanced_Pm(char *str)
{
	stack<char>balance;
	stack<char>balanceR;
	int i = 0;
	int evalL = 0;
	int evalR = 0;
	int real = 0;


	while (str[i] != '\0')
	{
		if (str[i] == '[')
		{
			balance.push('[');
			evalL++;
		}
		else if (str[i] == ']' && evalL>evalR)
		{
			balance.pop();
			evalR++;
		}
		else if (str[i] == ']')
		{
			balanceR.push(']');
			evalR++;
		}
		i++;
	}
	if (evalL == evalR)
	{
		for (; !balanceR.empty();)
		{
			balanceR.pop();
		}
	}
	if (!balanceR.empty())
		return false;

	if (!balance.empty())
		return false;

	else
		return true;


}
bool Balanced_Pl(char *str)
{
	stack<char>balance;
	stack<char>balanceR;
	int i = 0;
	int evalL = 0;
	int evalR = 0;
	int real = 0;


	while (str[i] != '\0')
	{
		if (str[i] == '{')
		{
			balance.push('{');
			evalL++;
		}
		else if (str[i] == '}' && evalL>evalR)
		{
			balance.pop();
			evalR++;
		}
		else if (str[i] == '}')
		{
			balanceR.push('}');
			evalR++;
		}
		i++;
	}
	if (evalL == evalR)
	{
		for (; !balanceR.empty();)
		{
			balanceR.pop();
		}
	}
	if (!balanceR.empty())
		return false;

	if (!balance.empty())
		return false;

	else
		return true;


}
char* Postfix(char *str)
{
	stack<char> s;
	static char restr[STRING_SIZE];
	int i = 0, j = 0;
	int operatorNum = 0, operandNum = 0;

	while (str[i] != '\0')
	{
		switch (str[i])
		{
			// 왼쪽 괄호 스텍에 push
		case '(':
			s.push(str[i]);
			break;

		case '[':
			s.push(str[i]);
			break;

		case '{':
			s.push(str[i]);
			break;

			//오른쪽 괄호일 경우 제대로 된 괄호치기가 된 것인지 판단, 다른 종류의 왼쪽 괄호일 경우 실패
			//실패하지 않을 경우 pop하여 배열에 저장(꺼내어 놓음)
		case ')':
			for (; s.top() != '(';)
			{
				if (s.top() == '{' || s.top() == '[')
				{
					cout << "Wrong parenthesis" << endl;
					exit(-1);
				}
				restr[j] = s.top();
				j++;
				s.pop();
			}
			if (s.top() == '(')
				s.pop();
			break;

		case ']':
			for (; s.top() != '[';)
			{
				if (s.top() == '{' || s.top() == '(')
				{
					cout << "Wrong parenthesis" << endl;
					exit(-1);
				}
				restr[j] = s.top();
				j++;
				s.pop();
			}
			if (s.top() == '[')
				s.pop();
			break;

		case '}':
			for (; s.top() != '{';)
			{
				if (s.top() == '(' || s.top() == '[')
				{
					cout << "Wrong parenthesis" << endl;
					exit(0);
				}
				restr[j] = s.top();
				j++;
				s.pop();
			}
			if (s.top() == '{')
				s.pop();
			break;

			//operand일 경우 배열에 저장(놓음)
		case 'a':
		case 'b':
		case 'c':
			restr[j] = str[i];
			j++;
			break;

			//연산자의 우선순위를 따져 pop하여 배열에 저장하고 자신은 push할지  그냥 push할지 판단
		case '@':
		case '#':
		case '&':
			if (s.empty())
				s.push(str[i]);
			else
			{
				if (Priority(str[i]) > Priority(s.top()))
				{
					s.push(str[i]);
				}
				else if (Priority(str[i]) <= Priority(s.top()))
				{
					restr[j] = s.top();
					j++;
					s.pop();
					s.push(str[i]);
				}

			}
			break;

		default:
			cout << "Wrong input!!" << endl;
			exit(-1);
			break;
		}

		if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c') operandNum++;
		else if (str[i] == '@' || str[i] == '#' || str[i] == '&') operatorNum++;
		i++;
	}

	if (operandNum != operatorNum + 1)
	{
		cout << "Error!!" << endl;
		exit(-1);
	}
	if (str[i] == '\0')//완전히 잘 되었는지 비교
	{
		while (!s.empty())
		{
			restr[j] = s.top();
			j++;
			s.pop();
		}
		restr[j] = '\0';
	}
	int z = 0;
	while (restr[z] != '\0')
	{
		cout << restr[z];
		z++;
	}
	cout << endl;

	return restr;
}
double Priority(char str1)
{
	double priority;
	switch (str1)//operator의 우선순위와 괄호가 top일 때 push할지를 결정
	{
	case '@':priority = 1;
		break;
	case '#':priority = 1;
		break;
	case '&':priority = 2;
		break;
	case '(':priority = 0.5;
		break;
	case '[':priority = 0.5;
		break;
	case '{':priority = 0.5;
		break;
	default: priority = 0.1;
		break;
	}
	return priority;
}



