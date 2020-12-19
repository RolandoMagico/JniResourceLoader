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
package rolandomagico.jniresourceloader;

public class ResourceLoader 
{
  static
  {
    final String archDataModel = System.getProperty("sun.arch.data.model");
    System.loadLibrary("libraries/ResourceLoader.Java." + archDataModel);
  }
  /**
   * Gets a translation for the specific menu entry.
   * 
   * @param library
   *        The path to the library containing the translation data. 
   * @param languageId
   *        The ID of the language.
   * @param menuId
   *        The ID of the menu entry.
   * @param defaultValue
   *        The default value which will be returned if no translation has been found.
   * @return
   *        The translated string.
   */
  public static native String getTranslatedString(
    final String library, final long languageId, final long menuId, final String defaultValue);
}
