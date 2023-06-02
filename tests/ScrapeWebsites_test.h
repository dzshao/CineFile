#ifndef SCRAPE_WEBSITE_TESTS
#define SCRAPE_WEBSITE_TESTS

#include <gtest/gtest.h>

#include "../header/webscraping/ScrapeWebsite.h"

TEST(ScrapingWebsiteTest, testBlankWebsite) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error: URL using bad/illegal format or missing URL\n");
    EXPECT_EQ(htmlResult, "");
}

TEST(ScrapingWebsiteTest, testIllegalURL) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("&&&&");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error: URL using bad/illegal format or missing URL\n");
    EXPECT_EQ(htmlResult, "");
}

TEST(ScrapingWebsiteTest, testIllegalURL2) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("@$");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error: URL using bad/illegal format or missing URL\n");
    EXPECT_EQ(htmlResult, "");
}

TEST(ScrapingWebsiteTest, testInvalidURL) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("hello.world.123.123");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error: Couldn't resolve host name\n");
    EXPECT_EQ(htmlResult, "");
}

TEST(ScrapingWebsiteTest, testInvalidURL2) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("cs100test123.");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error: Couldn't resolve host name\n");
    EXPECT_EQ(htmlResult, "");
}

TEST(ScrapingWebsiteTest, testSuccessfulURL) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("https://www.google.com");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
    EXPECT_EQ(htmlResult.substr(0, 15), "<!doctype html>");
}

TEST(ScrapingWebsiteTest, testSuccessfulURL2) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("https://www.imdb.com");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
    EXPECT_EQ(htmlResult.substr(0, 15), "<!DOCTYPE html>");
}

TEST(ScrapingWebsiteTest, testSuccessfulURL3) {
    testing::internal::CaptureStdout();
    string htmlResult = ScrapeWebsite::scrapeSite("https://github.com");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
    EXPECT_EQ(htmlResult.substr(0, 15), "\n\n\n\n\n\n<!DOCTYPE");
}

#endif
