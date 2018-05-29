import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;

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
		/*
		  new Thread(new Printer("Good!")).start();
		  new Thread(new Printer("Nice!")).start();
		*/
		/* I1-8
		   ThreadFactory factory = Executors.defaultThreadFactory();
		   factory.newThread(new Printer("Nice!")).start();
		   for(int i=0; i < 1000; i++){
		   System.out.print("Good!");
		}
		*/
		/* I1-9 */
		for(int i=0; i < 10; i++) {
			System.out.print("Good!");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				
			}
		}
	}
}
