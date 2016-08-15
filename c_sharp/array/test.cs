using System;

class Test
{
	public struct Entry
	{
		public string name;
		public int    value;
	};
	
	static public int FindPup(int max_ent, ref Entry[] ent,  ref int num_ent)
	{
		int ret = 0;
		Random rnd = new Random();
		num_ent = rnd.Next(1, max_ent);
		
		for(int i=0; i < num_ent; i++)
		{
			ent[i].name  = "name";
			ent[i].value = i;
		}
		
		return ret;
	}
	
	static void Main()
	{
		int ret;
		const int max_ent = 32;
		int num_ent = 0;

		System.Console.WriteLine("Test");
		System.Console.WriteLine("max_ent = {0}", max_ent);

		Entry[] ents = new Entry[max_ent];
		ret = FindPup(max_ent, ref ents, ref num_ent);
		System.Console.WriteLine("num_etn = {0}", num_ent);

		for(int i=0; i < num_ent; i++)
		{
			System.Console.WriteLine("{0} name={1}, value={2}", i, ents[i].name,
									 ents[i].value);
		}
	}
}