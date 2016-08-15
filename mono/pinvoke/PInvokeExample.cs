using System;
// P/Invokeサービス提供元
using System.Runtime.InteropServices;

namespace PInvokeExample
{
	public class Example1
	{
		//DllImportAttribute属性による数学ライブラリ（libm.so）の指定
		[DllImport("libm")]

		// 呼び出す関数のプロトタイプ宣言
		static extern double sqrt(double element);

		public static void Main(string[] args)
		{
			double e;

			if (args.Length == 1 && Double.TryParse(args[0], out e))
				{
					Console.WriteLine("「{0}」の平方根は「{1}」。", e, sqrt(e));
				}
			else
				{
					Console.WriteLine("Usage: PInvokeExample1.exe [数値]");
				}
		}
	}
}
