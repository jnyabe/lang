using System;
using Test;

namespace Test
{
	public class Test
	{

		public static void Main(string[] args)
		{
			double n = 3.0;
			double m = 2.0;
			double result = 0.0;
			
			result = MathUtil.Add(n, m);
			PrintUtil.Print(result);
			result = MathUtil.Sub(n, m);
			PrintUtil.Print(result);
			result = MathUtil.Mul(n, m);
			PrintUtil.Print(result);
			result = MathUtil.Div(n, m);
			PrintUtil.Print(result);
		}
	}
}
