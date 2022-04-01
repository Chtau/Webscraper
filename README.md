# Webscraper

A simple command line web scraper with the most basic features.

* external links
* internal links
* email addresses
* can follow internal links for deeper scans
* direct links output while scanning to the standard output

## Commands

|Argument|Example|Description|
|--------|-------|-----|
|1.)|https://news.ycombinator.com/|First argument must always be the url to scrape|
|-l={number}|-l=2|Scraping depth, default is 0 which means only the provided page will be scraped|
|-o|-o|When provided all found links will immediatley be written to the output|

## Example

Scans the page and returns all links when complete

```bash
./webscraper https://news.ycombinator.com/
```

Scans the page and follows internal links one level deep.
All discovered links will be printed immediatley.

```bash
./webscraper https://news.ycombinator.com/ -l=1 -o
```

## Build instruction

1.) Follow the instruction to install [curlpp](https://github.com/jpbarrette/curlpp) as it is required.

2.) CMAKE

```bash
cmake CMakeLists.txt
```

3.) MAKE

```bash
make
```

---
### Made by Christoph Taucher
License [MIT](LICENSE)