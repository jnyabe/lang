using System;

delegate int ShowMessage();

class Sample
{
	public int A()
	{
		Console.WriteLine("ShowpMessage 'A' is called");
		return 0;
	}

	public int B()
	{
		Console.WriteLine("ShowpMessage 'B' is called");
		return 1;
	}

	public int C()
	{
		Console.WriteLine("ShowpMessage 'C' is called");
		return 3;
	}
	
	public static void Main(string[] arg)
	{
		Sample s = new Sample();
		ShowMessage show_message;
#if false
		show_message = new ShowMessage(s.A);
		show_message();
		show_message = new ShowMessage(s.B);
		show_message();
#else
		show_message  = new ShowMessage(s.A);
		show_message += new ShowMessage(s.B);
		show_message += new ShowMessage(s.C);
		show_message();
#endif
	}
}