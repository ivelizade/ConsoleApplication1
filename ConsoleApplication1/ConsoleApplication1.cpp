#include "stdafx.h"
#include<iostream>
class PageInterface
{
public:
	virtual void setContent(std::string content) = 0;
	virtual std::string getContent() = 0;
	virtual int getNumber() = 0;
};
class readerInterface
{
	virtual std::string toString(PageInterface* page) = 0;
};
class PDFReader :readerInterface
{
public:
	std::string toString(PageInterface* page)override
	{
	return	page->getContent();
	}

};

 class DjVuReader :readerInterface
{
public:
	std::string toString(PageInterface* page)override
	{
		return	page->getContent();
	}

};

class PDFpage :public PageInterface
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
class Book
{
	std::string author;
	PageInterface**page;
public:
	int count = 0;
	Book(std::string Authour)
	{
		author = Authour;
		page = new PageInterface*[20];
	}
	std::string getAuthor() { return author; }
	auto getPage(int index) { return count > index ? page[index] : throw new std::exception("Invalid Index"); }
	auto getPageCount() { return count; }
	void addPage(PageInterface*Page)
	{
		page[Page->getNumber() ] = Page;
		count++;
	}

	Book() = default;

};
int main()
{
	Book b( std::string{ "Agatha Christie" });
	b.addPage(new PDFpage("my Content", 10));
	std::cout<<b.getPageCount();
	return 0;
}

