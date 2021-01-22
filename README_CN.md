# JsonLite
C++ JSON Library  
  
C++ 编写的JSON 库, 不依赖其他第三方库。  
支持Windows和Linux。  
  
所有模块都包含在"JsonLite.h"这个文件中。  
调用方法请参考"main.cpp"。 
  
|类|说明|
|---|---|
|JsonObjectBuilder|构造JSON对象|
|JsonArrayBuilder|构造JSON数组|
|JsonParser|解析JSON字符串|
|JsonFormater|格式化JSON字符串|
|JsonValue|所有的JSON值 (null, boolean, number, string, array, object) 在JsonLite中都是JsonValue|
|JString|JsohLite字符串类, 支持引用记数, 嵌入指针, 写时复制...|
|JPointe|JsohLite智能指针|
  
作者：3h6a@163.com
