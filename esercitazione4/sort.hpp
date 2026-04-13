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


