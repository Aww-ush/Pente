
bool Player::ResetGame()
{
    try
    {
        if (_board->ResetBoard())
        {
            cout << "there was error while resetting board" << endl;
            return false;
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}
