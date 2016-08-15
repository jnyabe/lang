

namespace Test 
{
	/// <summary>
	/// 数値計算ユーティリティー
	/// </summary>
	public class MathUtil
	{
		/// <summary>
		/// 2つの倍精度浮動小数点を加算する
		/// </summary>
		/// <remarks>
		///   <para>
		///     補足
		///   </para>
		/// </remarks>
		/// <param name="n">第一オペランド</param>
		/// <param name="m">第二オペランド</param>
		/// <returns>結果値</returns>
		static public double Add(double n, double m)
		{
			return n+m;
		}
	
		/// <summary>
		/// 2つの倍精度浮動小数点を減算する
		/// </summary>
		/// <remarks>
		///   <para>
		///     補足
		///   </para>
		/// </remarks>
		/// <param name="n">第一オペランド</param>
		/// <param name="m">第二オペランド</param>
		/// <returns>結果値</returns>
		static public double Sub(double n, double m)
		{
			return n-m;
		}

		/// <summary>
		/// 2つの倍精度浮動小数点を乗算する
		/// </summary>
		/// <remarks>
		///   <para>
		///     補足
		///   </para>
		/// </remarks>
		/// <param name="n">第一オペランド</param>
		/// <param name="m">第二オペランド</param>
		/// <returns>結果値</returns>
		static public double Mul(double n, double m)
		{
			return n*m;
		}

		/// <summary>
		/// 2つの倍精度浮動小数点を除算する
		/// </summary>
		/// <remarks>
		///   <para>
		///     補足
		///   </para>
		/// </remarks>
		/// <param name="n">第一オペランド</param>
		/// <param name="m">第二オペランド</param>
		/// <returns>結果値</returns>
		static public double Div(double n, double m)
		{
			return n/m;
		}
	}
}