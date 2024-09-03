#include "utils.hpp"


class Document {
public:
    Document(const string& documentType, const string& documentPath);

    string getDocumentType() const;
    string getDocumentPath() const;

private:
    string documentType;
    string documentPath;
};