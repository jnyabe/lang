using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace Test
{
	public class TypeTest
	{
		/// <summary>
		///   Constructor
		/// </summary>
		public TypeTest()
		{
		}
		/// <summary>
		///   テストの実行
		/// </summary>
		public void Run()
		{
			int res;
			res = TestSize();
			Console.WriteLine("TestSize: {0}", (res==0)? "OK":"NG");
			res = TestMisc();
			Console.WriteLine("TestMisc: {0}", (res==0)? "OK":"NG");
		}

		/// <summary>
		///   ビルトインタイプのサイズテスト
		/// </summary>
		private int TestSize()
		{
			object []  o_array = new object[] { 
				true, // System.Boolean
				1.0d, // System.Double
				1.0f, // System.Single
				1,    // System.Int32
				1U,   // System.UInt32
				1L,   // System.Int64
				1UL,  // SYstem.UInt64
				(short)1,   // System.Int16
				(ushort)1,  // System.UInt16
				"String" // System.String
			};
			
			for(int i = 0; i < o_array.Length; ++i)
				{
					Console.Write("Type: {0}", o_array[i].GetType().ToString());
					Console.WriteLine("Size: {0}", Marshal.SizeOf(o_array[i]));
				}
			
			Console.WriteLine("Size of bool: {0}", sizeof(bool));
			Console.WriteLine("Size of byte: {0}", sizeof(byte));
			Console.WriteLine("Size of sbyte: {0}", sizeof(sbyte));
			Console.WriteLine("Size of char: {0}", sizeof(char));
			Console.WriteLine("Size of decimal: {0}", sizeof(decimal));
			// Console.WriteLine("Size of double: {0}", sizeof(double));
			// Console.WriteLine("Size of float: {0}", sizeof(float));
			Console.WriteLine("Size of int: {0}", sizeof(int));
			Console.WriteLine("Size of uint: {0}", sizeof(uint));
			Console.WriteLine("Size of long: {0}", sizeof(long));
			Console.WriteLine("Size of ulong: {0}", sizeof(ulong));
			Console.WriteLine("Size of short: {0}", sizeof(short));
			Console.WriteLine("Size of ushort: {0}", sizeof(ushort));
			// Console.WriteLine("Size of string: {0}", sizeof(string));
			return 0;
		}

		private int TestMisc()
		{
			return 0;
		}
	}
}