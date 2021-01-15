#include "stdafx.h"
#include "JsonLite.h"

void Print(const char* pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);

	vprintf(pFormat, args);

	int len = _vscprintf(pFormat, args);
	char* buf = new char[len + 3];
	{
		vsprintf(buf, pFormat, args);
		buf[len] = '\r';
		++len;
		buf[len] = '\n';
		++len;
		buf[len] = 0;
		OutputDebugStringA(buf);

		delete[] buf;
	}
}

void TestStringifyO()
{
	JsonObjectBuilder builder;
	builder.Set("string", "abc");
	builder.Set("integer", 123);
	builder.Set("double", 3.14);
	builder.Set("array", JsonArrayBuilder()
		.Add("item1")
		.Add("item2"));
	builder.Set("object", JsonObjectBuilder()
		.Set("name1", "value1")
		.Set("name2", "value2"));
	Print("obj: %s", builder.Build());
}

void TestStringifyA()
{
	JsonArrayBuilder builder;
	builder.Add("abc");
	builder.Add(123);
	builder.Add(3.14);
	builder.Add(JsonArrayBuilder()
		.Add("item1")
		.Add("item2"));
	builder.Add(JsonObjectBuilder()
		.Set("name1", "value1")
		.Set("name2", "value2"));
	Print("ary: %s", builder.Build());
}

void Sample()
{
	JsonValue json = JsonParser::Parse("{}");

	//get array items
	for (UINT i = 0, l = json.GetLength(); i < l; ++i)
	{
		//way 1
		JString string1  = json.GetString(i);
		int     integer1 = json.GetInteger(i);

		//way 2
		JString string2  = json[i]->GetString();
		int     integer2 = json[i]->GetInteger();

		//way 3
		JString string3  = json.Get(i)->GetString();
		int     integer3 = json.Get(i)->GetInteger();
	}

	//get object items
	for (UINT i = 0, l = json.GetLength(); i < l; ++i)
	{
		JString name = json.GetName(i);

		//way 1
		JString string1  = json.GetString(name);
		int     integer1 = json.GetInteger(name);

		////way 2
		JString string2  = json[name]->GetString();
		int     integer2 = json[name]->GetInteger();

		//way 3
		JString string3  = json.Get(name)->GetString();
		int     integer3 = json.Get(name)->GetInteger();
	}

	//check whether the item exists
	if (json.Contain("value name"))
	{
		//TODO:
	}

	//get object item
	JsonValue obj = json.Get("object name");
	if (obj)
	{
		obj.GetString("value name");
	}

	//get array item
	JsonValue ary = json.Get("array name");
	if (ary)
	{
		ary.GetString(0);
	}
}

void TestParse()
{
	JsonObjectBuilder builder;
	builder.Set("string", "abc");
	builder.Set("integer", 123);
	builder.Set("double", 3.14);
	builder.Set("array", JsonArrayBuilder()
		.Add("item1")
		.Add("item2"));
	builder.Set("object", JsonObjectBuilder()
		.Set("name1", "value1")
		.Set("name2", "value2"));
	//Print(builder.Build());

	JsonValue json = JsonParser::Parse(builder.Build());
	for (UINT i = 0, l = json.GetLength(); i < l; ++i)
	{
		JString name = json.GetName(i);
		JString type = json.Get(name)->GetType();
		JString value = json.Get(name)->GetString();
		Print("Name=[%-7s] Type=[%-6s] ValueOfString=\"%s\"", name, type, value);
	}

	//Print(JsonFormater::Format(json, 4));
}

int _tmain(int argc, _TCHAR* argv[])
{
	//TestStringifyO();
	//TestStringifyA();
	TestParse();

	return 0;
}
