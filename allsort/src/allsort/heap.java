package allsort;

public class heap {
	public int length;
	public void heapify(int[] array,int i){
		int max = i;
		if(2*i+1 < length && array[i] < array[2*i+1])max = 2*i+1;
		if(2*i+2 < length && array[max] < array[2*i+2])max = 2*i+2;
		if(max != i){  //exit of secursion
			swap(array,i,max);
			heapify(array,max);
		}
	}
	public void buildheap(int[] array){
		length = array.length;
		for(int i = array.length/2; i>=0; i--){
			heapify(array,i);
		}
	}
	public void heapsort(int[] array){
		buildheap(array);
		for(int i = array.length - 1; i >= 0; i--){
			swap(array,0,i);
			length--;
			heapify(array,0);
		}
	}
	public static void swap(int[] array,int i,int j){
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] data = {5,4,1,8,3,7,5,2,9};
		heap he = new heap();
		he.heapsort(data);
		int n = 5;
		System.out.println(n=n++);
		System.out.println(n);
		for(int i = 0; i < data.length; i++ ){
			System.out.print(data[i]+" ");
		}
		

	}

}
