/**
 * @file    nsCharSetProber.cpp
 * @brief   nsCharSetProber
 * @license GPL 2.0/LGPL 2.1
 */

#include "nsCharSetProber.h"
#include "prmem.h"

//This filter applies to all scripts which do not use English characters
bool nsCharSetProber::FilterWithoutEnglishLetters(const char* aBuf, PRUint32 aLen, char** newBuf, PRUint32& newLen)
{
  char *newptr;
  char *prevPtr, *curPtr;
  
  bool meetMSB = false;   
  newptr = *newBuf = (char*)PR_Malloc(aLen);
  if (!newptr)
    return false;

  for (curPtr = prevPtr = (char*)aBuf; curPtr < aBuf+aLen; curPtr++)
  {
    if (*curPtr & 0x80)
    {
      meetMSB = true;
    }
    else if (*curPtr < 'A' || (*curPtr > 'Z' && *curPtr < 'a') || *curPtr > 'z') 
    {
      //current char is a symbol, most likely a punctuation. we treat it as segment delimiter
      if (meetMSB && curPtr > prevPtr) 
      //this segment contains more than single symbol, and it has upper ASCII, we need to keep it
      {
        while (prevPtr < curPtr) *newptr++ = *prevPtr++;  
        prevPtr++;
        *newptr++ = ' ';
        meetMSB = false;
      }
      else //ignore current segment. (either because it is just a symbol or just an English word)
        prevPtr = curPtr+1;
    }
  }
  if (meetMSB && curPtr > prevPtr) 
    while (prevPtr < curPtr) *newptr++ = *prevPtr++;  

  newLen = newptr - *newBuf;

  return true;
}

//This filter applies to all scripts which contain both English characters and upper ASCII characters.
bool nsCharSetProber::FilterWithEnglishLetters(const char* aBuf, PRUint32 aLen, char** newBuf, PRUint32& newLen)
{
  //do filtering to reduce load to probers
  char *newptr;
  char *prevPtr, *curPtr;
  bool isInTag = false;

  newptr = *newBuf = (char*)PR_Malloc(aLen);
  if (!newptr)
    return false;

  for (curPtr = prevPtr = (char*)aBuf; curPtr < aBuf+aLen; curPtr++)
  {
    if (*curPtr == '>')
      isInTag = false;
    else if (*curPtr == '<')
      isInTag = true;

    if (!(*curPtr & 0x80) &&
        (*curPtr < 'A' || (*curPtr > 'Z' && *curPtr < 'a') || *curPtr > 'z') )
    {
      if (curPtr > prevPtr && !isInTag) // Current segment contains more than just a symbol 
                                        // and it is not inside a tag, keep it.
      {
        while (prevPtr < curPtr) *newptr++ = *prevPtr++;  
        prevPtr++;
        *newptr++ = ' ';
      }
      else
        prevPtr = curPtr+1;
    }
  }

  // If the current segment contains more than just a symbol 
  // and it is not inside a tag then keep it.
  if (!isInTag)
    while (prevPtr < curPtr)
      *newptr++ = *prevPtr++;  

  newLen = newptr - *newBuf;

  return true;
}
