#include <iostream>
#include <string>

using namespace std;


class Box
{
public:

	Box()
	{

	}

	Box(int weight, int v, int pr)
	{
		this->weight = weight;
		this->v = v;
		this->pr = pr;

	}

	int GetV()
	{
		return v;
	}

	int GetWeight()
	{
		return weight;
	}

	int GetPr()
	{
		return pr;
	}

private:

	int v = 0;
	int weight = 0;
	int pr = 0;
};

class PaperBox : public Box
{
public:

	PaperBox(int weight, int v, int pr) : Box(weight, v, pr)
	{

	}

private:

	int v = 0;
	int weight = 0;
	int pr = 0;
};

class Thing
{
public:

	Thing()
	{

	}

	Thing(int weight2, int v2, int k)
	{
		this->weight2 = weight2;
		this->v2 = v2;
		this->k = k;
	}

	int GetV2()
	{
		return v2;
	}

	int GetWeight2()
	{
		return weight2;
	}

	int GetK()
	{
		return k;
	}

private:

	int v2 = 0;
	int weight2 = 0;
	int k = 0;
};

class Rice : public Thing
{
public:

	Rice(int weight2, int v2, int k) : Thing(weight2, v2, k)
	{

	}

private:

	int v2 = 0;
	int weight2 = 0;
	int k = 0;
};

class Pasta : public Rice
{
public:
	Pasta(int weight2, int v2, int k) : Rice(weight2, v2, k)
	{

	}

private:
	int v2 = 0;
	int weight2 = 0;
	int k = 0;
};


int Count(PaperBox& paperbox, Rice& rice, Pasta& pasta, int& count1, int& count2)
{

	int vb = paperbox.GetV();
	int weightb = paperbox.GetWeight();
	int pr = paperbox.GetPr();
	int vr = rice.GetV2();
	int weightr = rice.GetWeight2();
	int kr = rice.GetK();
	int vp = pasta.GetV2();
	int weightp = pasta.GetWeight2();
	int kp = pasta.GetK();
	int sum = 0;

	while (true)
	{

		if (vb >= vr && weightb >= weightr)
		{
			count1++;
			vb -= vr;
			weightb -= weightr;
			sum += kr;
		}
		if (vb >= vp && weightb >= weightp)
		{
			count2++;
			vb -= vp;
			weightb -= weightp;
			sum += kp;
		}
		else
		{
			break;
		}
		if (pr < sum)
		{
			cout << "Коробка не выдержала!" << endl;
			break;
		}


	}

	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int count1 = 0;
	int count2 = 0;

	PaperBox paperbox(2500, 1400, 10);

	Rice rice(900, 300, 2);

	Pasta pasta(450, 400, 3);

	Count(paperbox, rice, pasta, count1, count2);

	cout << "Вместилось " << count1 << " единиц(а) риса" << endl;
	cout << "Вместилось " << count2 << " единиц(а) макарон" << endl;

	return 0;
}