#include "ContribInc.h"

#include "kuromoji/Token.h"

namespace Lucene {
namespace Analysis {
namespace Ja {

const std::map<Type, String> TYPE_STRING_MAP = {{Type::KNOWN, L"Known"}, {Type::UNKNOWN, L"Unknown"}, {Type::USER, L"User"}};

Token::Token(int wordId, CharArray surfaceForm, int offset, int length, Type type, int position, Dict::DictionaryPtr dictionary)
	: _dictionary(dictionary)
	, _wordId(wordId)
	, _surfaceForm(surfaceForm)
	, _offset(offset)
	, _length(length)
	, _position(position)
	, _type(type)
{
}

String Token::toString()
{
	StringStream buffer;

	buffer << L"Token(\"" << String(_surfaceForm.get() + _offset, _length) << L"\", pos=" << _position << L", type="
		   << TYPE_STRING_MAP.at(_type) << L", wordId=" << _wordId << L", leftID=" << _dictionary->getLeftId(_wordId) << L")";

	return buffer.str();
}

CharArray Token::getSurfaceForm()
{
	return _surfaceForm;
}

int Token::getOffset()
{
	return _offset;
}

int Token::getLength()
{
	return _length;
}

String Token::getSurfaceFormString()
{
	return String(_surfaceForm.get() + _offset, _length);
}

String Token::getReading()
{
	return _dictionary->getReading(_wordId, _surfaceForm, _offset, _length);
}

String Token::getPronunciation()
{
	return _dictionary->getPronunciation(_wordId, _surfaceForm, _offset, _length);
}

String Token::getPartOfSpeech()
{
	return _dictionary->getPartOfSpeech(_wordId);
}

String Token::getInflectionType()
{
	return _dictionary->getInflectionType(_wordId);
}

String Token::getInflectionForm()
{
	return _dictionary->getInflectionForm(_wordId);
}

String Token::getBaseForm()
{
	return _dictionary->getBaseForm(_wordId, _surfaceForm, _offset, _length);
}

bool Token::isKnown()
{
	// Use JapaneseTokenizer::Type once JapaneseTokenizer converted
	return _type == Type::KNOWN;
}

bool Token::isUnknown()
{
	// Use JapaneseTokenizer::Type once JapaneseTokenizer converted
	return _type == Type::UNKNOWN;
}

bool Token::isUser()
{
	// Use JapaneseTokenizer::Type once JapaneseTokenizer converted
	return _type == Type::USER;
}

int Token::getPosition()
{
	return _position;
}

void Token::setPositionLength(int positionLength)
{
	this->_positionLength = positionLength;
}

int Token::getPositionLength()
{
	return _positionLength;
}
}
}
}
