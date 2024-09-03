#include "document.hpp"

// Document(const string& documentType, const string& documentPath);
Document::Document(const string &documentType, const string &documentPath)
    : documentType(documentType), documentPath(documentPath) {}

string Document::getDocumentType() const { return documentType; }

string Document::getDocumentPath() const { return documentPath; }
