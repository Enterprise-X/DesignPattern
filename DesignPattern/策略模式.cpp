#include "����ģʽ.h"

// ���������
class Strategy
{
public:
	Strategy() {}
	virtual void Sort(int arr[], int N) = 0;
};

// ������ԣ�ð������
class BubbleSort :public Strategy
{
public:
	BubbleSort() {
		printf("ð������_����\n");
	}
	void Sort(int arr[], int N) 
	{
		printf("����ð������:\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
};

// ������ԣ�ѡ������
class SelectionSort :public Strategy
{
public:
	SelectionSort() {
		printf("ѡ������_����\n");
	}
	void Sort(int arr[], int N) 
	{
		printf("����ѡ������:\n");
		int i, j, k;
		for (i = 0; i < N; i++)
		{
			k = i;
			for (j = i + 1; j < N; j++)
			{
				if (arr[j] < arr[k]) {
					k = j;
				}
			}
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
};

// ������ԣ���������
class InsertSort :public Strategy
{
public:
	InsertSort() {
		printf("��������_����\n");
	}
	void Sort(int arr[], int N) 
	{
		printf("���в�������:\n");
		int i, j;
		for (i = 1; i < N; i++)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (arr[i] > arr[j]) {
					break;
				}
			}
			int temp = arr[i];
			for (int k = i - 1; k > j; k--) {
				arr[k + 1] = arr[k];
			}
			arr[j + 1] = temp;
		}
	}
};



// ��������
class Context
{
public:
	Context() {
		arr = NULL;
		N = 0;
	}
	Context(int iArr[], int iN) {
		this->arr = iArr;
		this->N = iN;
	}
	void SetSortStrategy(Strategy* iSortStrategy) {
		this->sortStrategy = iSortStrategy;
	}
	void Sort() {
		this->sortStrategy->Sort(arr, N);
		printf("�����");
		this->Print();
	}
	void SetInput(int iArr[], int iN) {
		this->arr = iArr;
		this->N = iN;
	}
	void Print() {
		for (int i = 0; i < N; i++) {
			printf("%3d ", arr[i]);
		}
		printf("\n");
	}

private:
	Strategy* sortStrategy;
	int* arr;
	int N;
};

void ����ģʽ::����()
{
	std::cout << "********************����ģʽ********************" << std::endl;

	Context* ctx = new Context();

	int arr[] = { 7, 3, 13, 0, 66, 17, 36, 77, -33, -1, 11 };
	ctx->SetInput(arr, sizeof(arr) / sizeof(int));
	printf("����:");
	ctx->Print();

	// ð������
	ctx->SetSortStrategy(new BubbleSort());
	ctx->Sort();

	// ѡ������
	ctx->SetSortStrategy(new SelectionSort());
	ctx->Sort();

	// ��������
	ctx->SetSortStrategy(new InsertSort());
	ctx->Sort();

	std::cout << "************************************************" << std::endl;
}
