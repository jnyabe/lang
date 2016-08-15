 
using System;
using System.Reflection;

namespace Test
{
	

	/// <summary>
	/// プリント用のユーティリティークラス
	/// </summary>

	public class PrintUtil
	{
		/// <summary>
		/// 整数値をプリントする
		/// </summary>
		/// <remarks>
		///   <para>
		///     補足
		///   </para>
		/// </remarks>
		/// <param name="n">プリントする整数値</param>
		static public void Print(int n)
		{
			Console.WriteLine("[{0}] {1}", 
							  MethodBase.GetCurrentMethod().Name, n.ToString());
		}
	
		/// <summary>
		/// 浮動小数点をプリントする
		/// </summary>
		/// <remarks>
		/// </remarks>
		/// <param name="n">プリントする浮動小数点</param>
		static public void Print(float n)
		{
			Console.WriteLine("[{0}] {1}", 
							  MethodBase.GetCurrentMethod().Name, n);
		}

		/// <summary>
		/// 倍精度浮動小数点をプリントする
		/// </summary>
		/// <remarks></remarks>
		/// <param name="n">プリントする倍精度浮動小数点</param>
	
		static public void Print(double n)
		{
			Console.WriteLine("[{0}] {1}", 
							  MethodBase.GetCurrentMethod().Name, n.ToString());
		}

		/// <summary>
		/// 文字列をプリントする
		/// </summary>
		/// <remarks>
		///   <para name="str">
		///     String to be printted
		///   </para>
		/// </remarks>
		/// <param name="str">プリントする文字列</param>

		static public void Print(string str)
		{
			Console.WriteLine("[{0}] {1}", 
							  MethodBase.GetCurrentMethod().Name, str);
		}

	}
}