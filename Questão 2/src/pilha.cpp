#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string n[] = {"2", "3", "+", "5", "*"};
	int aux = sizeof(n)/sizeof(string);

	int cont = 0;

	stack<int> p;

	while(cont < aux)
	{
		if(n[cont] == "+" || n[cont] == "-" || n[cont] == "/" || n[cont] == "*")
		{
			int b = p.top();
			p.pop();
			int a = p.top();
			p.pop();

			if(n[cont] == "+")
			{
				p.push(a+b);
			}

			else if(n[cont] == "-")
			{
				p.push(a-b);
			}

			else if(n[cont] == "/")
			{
				p.push(a/b);
			}

			else
			{
				p.push(a*b);
			}

			cont++;
		}

		else
		{
			int valor = stoi(n[cont]);
			p.push(valor);
			cont++;
		}

	} 


	int result = p.top();

    cout << "Resultado: " << result << endl;

	return 0;
}