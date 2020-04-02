package com.company;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class WebCrawler {
    private static int MAX_DEPTH;
    private HashSet<String> links;

    public WebCrawler(int MaxDepth) {
        links = new HashSet<>();
        MAX_DEPTH = MaxDepth;
    }

    public void getPageLinks(String URL, int depth) {
        int x=URL.length();
        if (x>7){
        if((URL.charAt(x-1))=='/'){
            URL=URL.substring(0,x-1);
        }}
        else return;

        if ((!links.contains(URL) && (depth < MAX_DEPTH))) {
            System.out.println(">> Depth: " + depth + " [" + URL + "]");
            try {
                links.add(URL);

                Document document = Jsoup.connect(URL).get();
                Elements linksOnPage = document.select("a[href]");

                depth++;
                for (Element page : linksOnPage)
                    getPageLinks(page.attr("abs:href"), depth);

            } catch (IOException e) {
                System.err.println("For '" + URL + "': " + e.getMessage());
            }
        }
    }

    public void write(String filesrc) {
        try {
            PrintWriter out = new PrintWriter(filesrc);
            for (String link : links)
                out.println(link);
            out.close();
        }
        catch (IOException e) {
            System.out.println("error");
        }
    }
    public static void main(String[] args) {
        Scanner src = new Scanner(System.in);
        System.out.println("Vendosni url-ne fillestare");
        String url=src.next();
        System.out.println("Vendosni thellesine max");
        int thellesi = src.nextInt();
        System.out.println("Vendosni direktorine e skedarit");
        String filesrc = src.next();

        WebCrawler test1 = new WebCrawler(thellesi);
        test1.getPageLinks(url, 0);
        test1.write(filesrc);

    }
}
