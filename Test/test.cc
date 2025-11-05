
bool hasDuplicateCharacters(const std::string &str)
{

   bool charSet[128] = {false};

   for (char c : str)
   {
      if (charSet[c])
      {
         return true;
      }
      charSet[c] = true;
   }

   return false;
}