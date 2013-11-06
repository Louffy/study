package allsort;
import java.*;
public class bubble implements sort{
	public int[] doSort(int[] array){
		int flag = 0;
		for(int i = array.length; i > 0; i--){
			flag = 0;
			for(int j = 1; j < i; j++){
				if(array[j-1] > array[j]){
					swap(array,j-1,j);
					if(flag == 0)flag = 1;
				}
				
			}
			if(flag == 0)break;
			//System.out.println(i); //one sort time
		}
		return array;
	}
	public void swap(int[] array,int a,int b){
		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
	public static void main(String[] args){
		int data[] = {4,8,1,6,4,2,7,5};
		bubble bu = new bubble();
		data = bu.doSort(data);
		for(int i = 0;i < data.length; i++){
			System.out.print(data[i]);
		}
		System.out.println();
	}
}