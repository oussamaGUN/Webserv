#pragma once
#include "../HttpMessage/HttpMessage.hpp"



class Route {
private:
    std::string path;
    std::set<std::string> allowedMethods;
    bool autoindex;
    std::string defaultFile;

    // bool isDir;
    std::string uploadDir;
    std::set<std::string> cgiExtensions;
    std::string root;
    bool IsRedirection;
    std::string NewPathRedirection;
    int statusCodeRedirection;
public:
    void setPath(std::string path);
    std::string getPath();
    void addAllowedMethod(std::string method);
    std::set<std::string> getAllowedMethods();
    void setRoot(std::string root);
    std::string getRoot();
    void setDefaultFile(std::string defaultFile);
    std::string getDefaultFile();
    void setAutoindex(bool autoindex);
    bool getAutoindex();
    void addCgiExtension(std::string cgiExtension);
    std::set<std::string> getCgiExtensions();
    void setRedirectCode(int redirectCode);
    int getRedirectCode();
    void setRedirectnewPath(std::string redirectnewPath);
    std::string getRedirectnewPath();
    void setIsRedirection(bool IsRedirect);
    bool getIsRedirection();
    void setUploadDir(std::string uploadDir);
    std::string getUploadDir();
    // Route(const std::string& path) : path(path) {}
    // bool matches(const std::string& uri) const;
    // bool isMethodAllowed(const std::string& method) const;
};