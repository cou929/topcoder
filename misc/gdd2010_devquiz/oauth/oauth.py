# -*- coding:utf-8 -*-
import time, random, string, urllib2, cgi, hmac, hashlib

class oauth():
    oauth_params={}

    request_token_url = 'http://gdd-2010-quiz-japan.appspot.com/oauth/f769083a642cab4135939e68'

    
    def __init__(self):
        self.oauth_params = {
            "oauth_consumer_key": 'f769083a642cab4135939e68',
            "oauth_consumer_secret": 'd61c900a32fc9dbc283aead5',
            "oauth_timestamp": str(int(time.time())),
            "oauth_nonce": 'devquiz',
            "oauth_signature_method": 'HMAC-SHA1',
            "oauth_version": '1.0'
            }

    def getAuthSignatureBaseString(self):
        return string.join([i+'='+self.oauth_params[i] for i in sorted(self.oauth_params) if i != 'oauth_consumer_secret'],"&")

    def getRequestToken(self, *args):
        return string.join([urllib2.quote(i,"") for i in args],"&")

    def getOauthSignature(self, msg):
        return hmac.new(self.oauth_params["oauth_consumer_secret"]+'&', msg, hashlib.sha1).digest().encode("base64").strip()

    def getRequestTokenURL(self,url,signature):
        rtu = url + '?' + string.join([i + '=' + urllib2.quote(self.oauth_params[i], "") for i in sorted(self.oauth_params) if i != 'oauth_consumer_secret'], "&")
        return rtu

    def go(self):
        asbs = self.getAuthSignatureBaseString()
        rt = self.getRequestToken('GET', self.request_token_url, asbs)
        os = self.getOauthSignature(rt)
        rtu = self.getRequestTokenURL(self.request_token_url, os)
        return rtu
       
        return {'token':token,'token_secret':token_secret}




'http://gdd-2010-quiz-japan.appspot.com/oauth/f769083a642cab4135939e68?
oauth_consumer_key=f769083a642cab4135939e68&
oauth_nonce=devquiz&
oauth_signature_method=HMAC-SHA1&
oauth_timestamp=1281881300&
oauth_version=1.0'

