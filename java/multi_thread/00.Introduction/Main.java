public class Main {
	public static void main(String[] args)
	{
		/*		
		MyThread t = new MyThread();
		t.start();
		for(int i=0; i < 1000; i++) {
			System.out.print("Good!");
		}
		*/
		/*
		new PrintThread("Good!").start();
		new PrintThread("Nice!").start();
		*/
		new Thread(new Printer("Good!")).start();
		new Thread(new Printer("Nice!")).start();
		
	}
}
