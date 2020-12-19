/***********************************************************************************************************************
 MIT License

 Copyright(c) 2020 Roland Reinl

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files(the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions :

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
***********************************************************************************************************************/

/***********************************************************************************************************************
 INCLUDES
***********************************************************************************************************************/
#include "rolandomagico_jniresourceloader_ResourceLoader.h"
#include "ResourceLoader.h"
#include <string>

using namespace std;
using namespace RolandoMagico;
/***********************************************************************************************************************
 DEFINES
***********************************************************************************************************************/

/***********************************************************************************************************************
 TYPES
***********************************************************************************************************************/

/***********************************************************************************************************************
 LOCAL CONSTANTS
***********************************************************************************************************************/

/***********************************************************************************************************************
 LOCAL VARIABLES
***********************************************************************************************************************/

/***********************************************************************************************************************
 LOCAL FUNCTION DECLARATIONS
***********************************************************************************************************************/

/***********************************************************************************************************************
 IMPLEMENTATION
***********************************************************************************************************************/
JNIEXPORT jstring JNICALL Java_rolandomagico_jniresourceloader_ResourceLoader_getStringResource
(JNIEnv* env, jclass instance, jstring library, jlong resourceId)
{
  jstring result = nullptr;

  if ((library != nullptr) && (resourceId <= UINT32_MAX))
  {
    jboolean isCopy;
    const jchar* libraryChars = env->GetStringChars(library, &isCopy);

    if (libraryChars != nullptr)
    {
      ResourceLoader loader;
      wstring path = (wchar_t*)libraryChars;
      wstring* resourceValue = loader.LoadStringResource(path, (uint32_t)resourceId);
      if (resourceValue != nullptr)
      {
        env->NewString((const jchar*)resourceValue->c_str(), (jsize)resourceValue->length());
        delete resourceValue;
      }

      env->ReleaseStringChars(library, libraryChars);
    }
  }
  
  return result;
}
/***********************************************************************************************************************
 EOF
***********************************************************************************************************************/