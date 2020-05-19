static int Partition(int *pInt, int i, int j);

//
// Created by junhai on 2020/4/21.
//
void _shellSort(int s[], int n){
    int i,j,tmp,gap = n; //希尔增量
    while ((gap = gap/2) >= 1) { //分组长度折半
        for(i = 0 ;i < gap; i ++) { //gap长度个分组
            for(j=i+gap;j < n;j += gap) { //分组元素
                //插入排序？ //仅仅交换？
                if(s[j] < s[j-gap]) {
                    tmp = s[j];
                    s[j] = s[j-gap];
                    s[j-gap] = tmp;
                }
            }
        }
    }
}

/**
 * 1.优化中轴选择三数区中&不必要交换 2.递归
 * @param a
 * @param low
 * @param high
 */
void quickSort(int *a,int low,int high) {
    if(low < high){
        int pivotKey = Partition(a,low,high);
        quickSort(a,pivotKey+1,high);
        quickSort(a,low,pivotKey-1);
    }
}

void quickSort2(int *a,int low,int high) {
    while (low < high){
        int pivotKey = Partition(a,low,high);
        quickSort(a,low,pivotKey-1);
        low = pivotKey+1;
    }
}

/**
 * 交换数组元素
 * @param a
 * @param i
 * @param j
 */
static void swap(int *a,int i,int j) {
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

static int Partition(int *a,int low,int high) {
    int pivot = a[low];

    while(low < high) {
        while(low < high && a[high] >= pivot) { //找到第一个小于pivot的位置
            high--;
        }
        swap(a,low,high);//high存储

        while (low < high && a[low] <= pivot) { //找到第一个大于pivot的位置
            low++;
        }
        swap(a,low,high); //最后一次无效交换
    }
    return low; //中轴所在位置
}

static int Partition2(int *a,int low,int high) {
    int pivot = a[low];
    while(low < high) {
        while(low < high && a[high] >= pivot) { //找到第一个小于pivot的位置
            high--;
        }
        a[low] = a[high];

        while (low < high && a[low] <= pivot) { //找到第一个大于pivot的位置
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivot; //复位枢轴数据
    return low; //中轴所在位置
}
