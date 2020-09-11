class Score {
  private:
    long m_partie;
    std::string m_pseudonym;
    long m_score;
  public:
    Score(long partie, std::string pseudonym, long score)
      : m_partie(partie)
      , m_pseudonym(pseudonym)
      , m_score(score) {}

    long getPartie(){
      return m_partie;
    }

    std::string getPseudonym(){
      return m_pseudonym;
    }

    long getScore(){
      return m_score;
    }
};