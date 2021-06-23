import "./Footer.css";

function Footer() {
    return (
        <div className="footer">
            <div className="contact-info">
                <h3>Contact</h3>
                <div>
                    <i class="fas fa-at fa-1x"></i> 이메일: aaxx98@naver.com
                </div>
                <div>
                    <a href="https://github.com/aaxx98">
                        <i class="fab fa-github fa-1x"></i> 깃허브(aaxx98)
                    </a>
                </div>
                <div>
                    <a href="https://blog.naver.com/aaxx98">
                        <i class="fas fa-home fa-1x"></i> 네이버 블로그
                    </a>
                </div>
            </div>
        </div>
    );
}

export default Footer;
