#include "stdafx.h"
class PageInterface
{
	virtual void setContent(std::string content) = 0;
	virtual std::string getContent() = 0;
	virtual int getNumber() = 0;
};
class PDFpage:public PageInterface
{
	std::string content;
	int number;
public:
	void setContent(std::string Content) override
	{
		content = Content;
	}
	std::string getContent() override
	{
		return content;
	}
	int getNumber()override
	{
		return number;
	}
	PDFpage(std::string Content, int Number)
	{
		content = Content;
		number = Number;
	}
	PDFpage() = default;

};
class DjVuPage :public PageInterface
{
	std::string content;
	int number;
public:
	void setContent(std::string Content) override
	{
		content = Content;
	}
	std::string getContent() override
	{
		return content;
	}
	int getNumber()override
	{
		return number;
	}
	DjVuPage(std::string Content, int Number)
	{
		content = Content;
		number = Number;
	}
	DjVuPage() = default;
};
template<typename T>
class Book
{
	std::string author;
	T*page;
public:
	Book(std::string Authour, int Page)
	{
		author = Authour;
		page = Page;
	}
	std::string getAuthor() { return author; }
	int getPage() { return page; }
	void addPage( PageInterface*page) 
	{

	}
	Book();

};
int main()
{

	return 0;
}

