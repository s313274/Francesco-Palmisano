#pragma once
#include <vector>

template <typename T>
bool is_sorted(const std::vector<T>& v)
{
	if (v.size()<=1)
	{
		return true;
	}
	
	for (int i=0; i<v.size()-1; i++)
	{
		if (v[i]<=v[i+1])
		{
			
		}
		else
		{
			return false;
		}
	}
	return true;
}


template <typename T>
void bubble_sort(std::vector<T>& v)
{
	if (v.size()<=1)
	{
		return;
	}
	
	for (int i=0; i<v.size()-1; i++)
	{
		for (int j=v.size()-1; j>i; j--)
		{
			if(v[j]<v[j-1])
			{
				T k=v[j];
				v[j]=v[j-1];
				v[j-1]=k;
			}
		}
	}
}

template <typename T>
void insertion_sort(std::vector<T>& v)
{
	if (v.size()<=1)
	{
		return;
	}
	
	for (int j=1; j<v.size(); j++)
	{
		T key = v[j];
		int i = j - 1;
		while (i>=0 && v[i]>key)
		{
			v[i+1]=v[i];
			i--;
		}
		v[i+1]=key;
	}
}


template <typename T>
void selection_sort(std::vector<T>& v)
{
	if (v.size()<=1)
	{
		return;
	}
	
	for (int i=0; i<v.size()-1; i++)
	{
		int min=i;
		for (int j=i+1; j<v.size(); j++)
		{
			if (v[j]<v[min])
			{
				min=j;
			}
		}
		T k=v[i];
		v[i]=v[min];
		v[min]=k;
	}
}


template <typename T>
void merge(std::vector<T>& A, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2= r-q;
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	for(int i=0; i<n1; i++)
	{
		L[i]=A[p+i];
	}
	for(int j=0; j<n2; j++)
	{
		R[j]=A[q+j+1];
	}
	
	int i=0;
	int j=0;
	int k=p;
	while (i<n1 && j<n2) 
	{
		if (L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	while (i < n1) 
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) 
	{
		A[k] = R[j];
		j++;
		k++;
	}
}

template <typename T>
void mergesort(std::vector<T>& A, int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}


template <typename T>
int partition(std::vector<T>& A, int p, int r)
{
		T x=A[r];
		int i=p-1;
		
		for(int j=p; j<=r-1; j++)
		{
			if(A[j]<=x)
			{
				i++;
				T k=A[j];
				A[j]=A[i];
				A[i]=k;
			}
		}
		
		T k=A[i+1];
		A[i+1]=A[r];
		A[r]=k;
		
		return i+1;
}

template <typename T>
void quicksort(std::vector<T>& A, int p, int r)
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

template <typename T>
void insertion_sort_part(std::vector<T>& v, int p, int r)
{	
	for (int j=p+1; j<=r; j++)
	{
		T key = v[j];
		int i = j - 1;
		while (i>=p && v[i]>key)
		{
			v[i+1]=v[i];
			i--;
		}
		v[i+1]=key;
	}
}

template <typename T>
void quick_insertion_sort(std::vector<T>& A, int p, int r)
{
	const int S=50;
	int dp= r-p+1;
	
	if(dp<=S)
	{
		insertion_sort_part(A,p,r);
	}
	else
	{
		if(p<r)
		{
			int q=partition(A,p,r);
			quick_insertion_sort(A,p,q-1);
			quick_insertion_sort(A,q+1,r);
		}
	}
}