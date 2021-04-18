#include<stdio.h>
#include<stdlib.h>
#include<qgsort.h>
void insertSort(int *a,int n){
    int temp;
    int i,j;//循环变量
    for(i=1;i<n;i++)//递增排序
    {
        temp=a[i];
        for(j=i-1;j>=0&&temp<a[j];j--)
            a[j+1]=a[j];
            a[j+1]=temp;
    }
}
void MergeArray(int *a,int begin,int mid,int end,int *temp){
    int i = begin,j = mid + 1;
    int m = mid,n = end;
    int k = 0;
    //开始合并两个数组；
    while(i <= m && j <= n){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i <= m){
        temp[k++] = a[i++];
    }
    while(j <= n){
        temp[k++] = a[j++];
    }
    //把temp数组中的结果装回a数组
    for(i = 0;i < k;i++){
        a[begin + i] = temp[i];
    }
}
void MergeSort(int *a,int begin,int end,int *temp){
    if(begin < end){
        int mid = (begin + end) / 2;
        MergeSort(a,begin,mid,temp);   //左边有序
        MergeSort(a,mid + 1,end,temp);   //右边有序
        MergeArray(a,begin,mid,end,temp); //将左右两边有序的数组合并
    }
}
void QuickSort_Recursion(int *a, int begin, int end){
    if(begin<end)
    {
        int temp = a[begin];
        int i=begin;
        int j=end;
        while(i<j)
        {
            while(i<j&&a[j]>temp)
                j--;
            a[i]=a[j];
            while(i<j&&a[i]<=temp)  //此处为小于等于,否则不能处理相等的元素
                    i++;
            a[j]=a[i];
        }
        a[i]=temp;
        QuickSort(a,begin,i-1);
        QuickSort(a,i+1,end);
    }
    else
        return ;
}
void CountSort(int *a, int size , int max){
    int *c, *b;
    int i;
    /*临时数组,注意它的大小是待排序序列中值最大的那个。
    如假定该排序序列中最大值为1000000，则该数组需要1000000*sizeof(int)个存储单元*/
    c = (int *)malloc(sizeof(int)*max);
    b = (int *)malloc(sizeof(int)*size); /*存放排序结果的数组*/
    for (i = 0; i < max; i++)
        c[i] = 0;  /*初始化*/
    for (i = 0; i < size; i++)
        c[a[i]] += 1; /*统计数组A中每个值为i的元素出现的次数*/
    for (i = 1; i < max; i++)
        c[i] = c[i - 1] + c[i]; /*确定值为i的元素在数组c中出现的位置*/
    for (i = size - 1; i >= 0; i--){
        b[c[a[i]] - 1] = a[i]; /*对A数组，从后向前确定每个元素所在的最终位置;*/
        c[a[i]] -= 1;
    }
    for (i = 0; i < size; i++)
        a[i] = b[i];/*这个目的是返回A数组作为有序序列*/
    free(c);
    free(b);
}
void RadixCountSort(int *a,int size){
    assert(a);
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = a[0], min = a[0];
	for (int i = 0; i < size; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将临时数组都初始化为0
	int *b = (int *)calloc(max - min + 1, sizeof(int));
	//使用临时数组记录原始数组中每个数所出现的个数
	for (int i = 0; i < size; i++){
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (int i = 0; i < max - min; i++){
		while (b[i] > 0 && j < size){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
			--b[i];
		}
	}
	//释放临时数组
	free(b);
	b = NULL;
}