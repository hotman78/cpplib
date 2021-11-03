* ネームスペース　geometry2d  
   * EPS(浮動小数点精度)　2つの数の差がこれ以下ならば、一致するとみなす
   * sgn()　与えられた数がEPSを加味して、正 or 負 or 0　を返す。
   * 構造体　Point(これは自作する場合の話です)  
       * (x, y)の2つの値を持つ　座標でもあり、位置ベクトルともみなす
       * 構造体に関する基本演算(点同士の加減算、一致、定数倍)
       * length()　その点の(0, 0)からの距離(位置ベクトルとみなした時の長さでもある)  
       * lengthSquare()　length()の二乗
       * isZero()　(0, 0)と同じかどうかを返す
       * rotation()　与えられた角度(弧度法)だけ(0, 0)中心に回転させる
       * angle()　(0, 0)中心の円の上に乗ってるとしたときの偏角
       * dot()　引数にとった座標をベクトルとみなして、内積を返す
       * cross()　引数にとった座標をベクトルとみなして、2次元版外積を返す((a, b).cross(c, d) == a * d - b * c)
       * distanceFrom()　引数にとった座標までの距離を返す
       * normalized()　自身を位置ベクトルとみなした時
       * normalUnitVector()　自身の単位法線ベクトルを1つ返す
   * 入出力ストリームのオーバーロード
   * 定数倍乗算の演算子(どの順番でもかけられるようにするため)
   * '>'演算子　x座標を優先的に比較し、その次にy座標を比較する
   * error_val　解なしなどになったときに返される値。
   * ==演算子　(どの順番でも比較できるようにするため)
   * iSP()　3点の位置関係を返す関数。
 
   * ネームスペース　Line
       * 構造体 Line
           * Point型の始点と終点を持つ(無向直線ならば、始点と終点に意味はない)
           * ax+by+c=0型のコンストラクタも
           * vec()　(end - begin)のベクトルも返せるように
       
       * Lineの別名として、Segmentを定義　明確に線分を扱う場合はSegmentという型名にする。
       * lineIntersection()　与えられた直線の交点を返す　存在しないならerror_val
       * segmentIntersection()　与えられた線分の交点を返す　複雑な仕様あり
       * distanceBetweenPointAndLine()　与えられた点と直線の距離を返す
       * distanceBetweenPointAndSegment()　与えられた点と直線の距離を返す
       * distanceBetweenSegmentAndSegment()　与えられた線分と線分の距離を返す
       * projection()　与えられた点と直線について、正射影を返す
       * reflection()　与えられた点と直線について、線対称の点(鏡映)を返す